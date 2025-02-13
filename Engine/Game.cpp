/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game (MainWindow& wnd)
	:
	wnd (wnd),
	gfx (wnd),
	board (gfx),
	sprites(),
	position (116, 16) // Top left corner of board, to set board in center of 800 x 600 screen
{
	for(int i = 0; i < _total_men; i++) {
		if(i >= _men_per_side) {
			players[i].InitPosition (board.GetTileLocation (i + 8));
			players[i].SetSpecificTile (i + 8);
			board.SetOccupiedBy (i + 8, PlayerType::p1);
		} else {
			players[i].InitPosition (board.GetTileLocation (i));
			players[i].SetSpecificTile (i);
			board.SetOccupiedBy (i, PlayerType::p2);
		}
		players[i].InitStatus ();
	}
}

void Game::Go () {
	gfx.BeginFrame ();
	UpdateModel ();
	ComposeFrame ();
	gfx.EndFrame ();
}


/////////////////////////////////////// MAIN OUTPUT AREA //////////////////////////////////////////////////////////////////////////


void Game::UpdateModel () {
	
	if(!game_begin && !game_win) {
		if(wnd.kbd.KeyIsPressed (VK_RETURN)) {
			game_begin = true;
		}
	} else {
		const Position mouse_position (wnd.mouse.GetPos ());
		auto now = std::chrono::steady_clock::now ();

		CheckForKing ();
		UpdatePlayerStatus (mouse_position, now);
		UpdateBoardHover (mouse_position);
		HandlePlayerMovement (mouse_position, now);
		if(p1_destroyed == 12 || p2_destroyed == 12) {
			game_win = true;
		}
	}
}

void Game::ComposeFrame () {
	DrawTable ();
	board.Draw (position);

	if(!game_begin) {
		sprites.DrawPressEnter (gfx);
	} else {
		for(int i = 0; i < _total_men; ++i) {
			if(players[i].GetStatus () != PieceType::destroyed) {
				if(i >= _men_per_side) {
					players[i].Draw (gfx, players[i].GetPosition (), players[i].GetStatus (), PlayerType::p1, false);
				} else {
					players[i].Draw (gfx, players[i].GetPosition (), players[i].GetStatus (), PlayerType::p2, false);
				}
			}
		}
		for(int i = 0; i < _total_men; ++i) {
			players[i].DrawSelectStatus (gfx, players[i].GetPosition (), players[i].GetSelectStatus ());
		}

		for(int i = 0; i < _total_moveable_tiles; ++i) {
			for(int j = 0; j < _total_men; ++j) {
				if(GetPossibleMoves (i) && (board.GetOccupiedBy (i) == PlayerType::p0) && players[j].GetSelected ()) {
					DrawMoveableTile (board.GetTileLocation (i).x, board.GetTileLocation (i).y, false);
				}
				if(GetAdditionalMoves (i)) {
					DrawMoveableTile (board.GetTileLocation (i).x, board.GetTileLocation (i).y, true);
				}
			}
		}
	}

	sprites.DrawPlayer1 (gfx);
	DrawDestroyed (p2_destroyed, PlayerType::p2);
	sprites.DrawPlayer2 (gfx);
	DrawDestroyed (p1_destroyed, PlayerType::p1);
	if(game_win) {
		if(p1_destroyed == 12) {
			sprites.DrawWinner (gfx, PlayerType::p2, Colors::Yellow);
		} else {
			sprites.DrawWinner (gfx, PlayerType::p1, Colors::Magenta);
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::UpdatePlayerStatus (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now) {
	const int group_begin = PlayerTurn () ? _men_per_side : 0;
	const int group_end = PlayerTurn () ? _total_men : _men_per_side;
	
	for(int i = group_begin; i < group_end; ++i) {
		
		const Position top_left = players[i].GetPosition () - _circle_half_width;
		const Position bottom_right = players[i].GetPosition () + _circle_half_width;
		PlayerType player_check = (i >= 12) ? PlayerType::p1 : PlayerType::p2;
		bool is_king = (PieceType::king == players[i].GetStatus () ? true : false);
		
		if(players[i].GetStatus () == PieceType::destroyed) { continue; }

		if(players[i].GetSelected () && jump_again) {
			ParityMoves ();
			players[i].UpdateSelectStatus (PlayerStatus::select);
			jump_again = false;
			ResetCanMoveTo ();
			CanMoveTo (player_check, i, players[i].GetSpecificTile (), is_king, true);
			continue;
		}

		if(mouse_position >= top_left && mouse_position <= bottom_right && !players[i].GetSelected ()) {
			players[i].UpdateSelectStatus (PlayerStatus::hover);
		} else if(!players[i].GetSelected()) {
			players[i].UpdateSelectStatus (PlayerStatus::non);
		}
		
		if(players[i].GetSelectStatus () == PlayerStatus::hover && wnd.mouse.LeftIsPressed ()) {
			ResetCanMoveTo ();
			CanMoveTo (player_check, i, players[i].GetSpecificTile (), is_king, false);
			if(HasMoves ()) {
				DeselectAllPlayers ();
				players[i].SetSelected ();
				players[i].UpdateSelectStatus (PlayerStatus::select);
			} else {
				DeselectAllPlayers ();
			}
		}
			
		if(mouse_position >= top_left && mouse_position <= bottom_right && players[i].GetSelected ()) {
			if(wnd.mouse.RightIsPressed ()) {
				players[i].UpdateSelectStatus (PlayerStatus::non);
				players[i].SetSelected ();
				ResetCanMoveTo ();
			}
		}
	}
}

void Game::HandlePlayerMovement (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now) {

	for(int i = 0; i < _total_men; ++i) {
		for(int j = 0; j < _total_moveable_tiles; ++j) {
			if(players[i].GetSelected () && board.GetTileHover (j) && wnd.mouse.LeftIsPressed () && GetPossibleMoves(j)) {
				_last_click_time = now;
				
				
				// When subtracting start position from end position, or vice versa, the absolute values
				// possible are 3, 4, 5, 7, and 9. If they are 7 or 9, then a jump took place.
				int jump_check = abs (players[i].GetSpecificTile () - j);
				int clear_tile = GetJumpTile (players[i].GetSpecificTile (), j);
				
				if(jump_check == move_seven || jump_check == move_nine) {
					DestroyIt (clear_tile);
					board.SetOccupiedBy (clear_tile, PlayerType::p0);
				}

				for(int k = 0; k < _total_moveable_tiles; ++k) {
					jump_again = GetAdditionalMoves (k);
					if(jump_again) { break; }
				}
	
				players[i].UpdatePosition (i, board.GetTileLocation (j));
				board.SetOccupiedBy (players[i].GetSpecificTile (), PlayerType::p0);
				players[i].SetSpecificTile (j);
				board.SetOccupiedBy (j, (i >= 12 ? PlayerType::p1 : PlayerType::p2));
				
				if(jump_again) {
					continue;
				} else {
					players[i].SetSelected ();
					players[i].UpdateSelectStatus (PlayerStatus::non);
					ResetCanMoveTo ();
					++_move_counter;
				}
				
			}
		}
	}
}

void Game::UpdateBoardHover (const Position& mouse_position) {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		const Position top_left = board.GetTileLocation (i) - _square_half_width;
		const Position bottom_right = board.GetTileLocation (i) + _square_half_width;
		bool selected_on_board = IsPlayerSelected ();

		if(mouse_position >= top_left && mouse_position <= bottom_right && (board.GetOccupiedBy (i) == PlayerType::p0) && selected_on_board) {
			board.SetTileHover (i, true);
		} else {
			board.SetTileHover (i, false);
		}
	}
}

bool Game::IsPlayerSelected () const {
	for(int i = 0; i < _total_men; ++i) {
		if(players[i].GetSelected ()) {
			return true;
		}
	}
	return false;
}

void Game::DeselectAllPlayers () {
	for(int i = 0; i < _total_men; ++i) {
		if(players[i].GetSelected ()) {
			players[i].SetSelected ();
			break;
		}
	}
}

bool Game::PlayerTurn () const {
	return (_move_counter % 2 == 0) ? true : false;
}

void Game::DrawTable () {
	for(int y = 0; y < gfx.ScreenHeight; ++y) {
		for(int x = 0; x < gfx.ScreenWidth; ++x) {
			if(x > 109 && x < 689 && y > 9 && y < 589) {
				gfx.PutPixel (x, y, Colors::Black);
			} else {
				gfx.PutPixel (x, y, Color (15, 45, 15));
			}
		}
	}
}

void Game::CanMoveTo (const PlayerType which_player, const int which_man, const int which_tile, bool is_king, bool only_jump) {
	const auto & jumps = is_king ? king_jumps : (which_player == PlayerType::p1 ? p1_jumps : p2_jumps);
	const auto & moves = is_king ? king_moves : (which_player == PlayerType::p1 ? p1_moves : p2_moves);

	// Check for jump moves
	for(int jump : jumps[which_tile]) {
		int tile_to_jump = GetJumpTile (which_tile, jump);
		if(board.GetOccupiedBy (tile_to_jump) == (which_player == PlayerType::p1 ? PlayerType::p2 : PlayerType::p1) &&
			board.GetOccupiedBy (jump) == PlayerType::p0) {
			_can_move_to[jump] = true;
		}
		
		// Check for additional jumps
		for(int extra_jump : jumps[jump]) {
			int next_tile_to_jump = GetJumpTile (jump, extra_jump);
			if(board.GetOccupiedBy (next_tile_to_jump) == (which_player == PlayerType::p1 ? PlayerType::p2 : PlayerType::p1) &&
				board.GetOccupiedBy (extra_jump) == PlayerType::p0 && _can_move_to[jump]) {
				_additional_jumps[extra_jump] = true;
			}
		}
	}

	// Check for regular moves
	if(!only_jump) {
		for(int move : moves[which_tile]) {
			if(board.GetOccupiedBy (move) == PlayerType::p0) {
				_can_move_to[move] = true;
			}
		}
	}
}

void Game::DrawMoveableTile (int board_x, int board_y, bool additional) {
	if(!additional) {
		gfx.DrawRing (board_x, board_y, 10, 12, Colors::Green);
	} else {
		gfx.DrawRing (board_x, board_y, 10, 12, Color(148, 125, 152));
	}
	
}

bool Game::GetPossibleMoves (const int which_tile) const {
	return _can_move_to[which_tile];
}

bool Game::GetAdditionalMoves (const int which_tile) const {
	return _additional_jumps[which_tile];
}

void Game::ParityMoves () {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		_can_move_to[i] = _additional_jumps[i];
	}
}

void Game::ResetCanMoveTo () {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		_can_move_to[i] = false;
		_additional_jumps[i] = false;
	}
}

void Game::CheckForKing () {
	for(int i = 0; i < _total_men; ++i) {
		if(i >= _men_per_side) {
			if(players[i].GetSpecificTile () == 0 ||
				players[i].GetSpecificTile () == 1 ||
				players[i].GetSpecificTile () == 2 ||
				players[i].GetSpecificTile () == 3) {
				players[i].UpdateStatus (PieceType::king);
			}
		} else {
			if(players[i].GetSpecificTile () == 28 ||
				players[i].GetSpecificTile () == 29 ||
				players[i].GetSpecificTile () == 30 ||
				players[i].GetSpecificTile () == 31) {
				players[i].UpdateStatus (PieceType::king);
			}
		}
	}
}

bool Game::HasMoves () {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		if(_can_move_to[i]) {
			return true;
		}
	}
	return false;
}

// This could be done with unordered maps, I just find this easier to understand, right now.
int Game::GetJumpTile (const int start_tile, const int end_tile) const {
	switch(start_tile) {
	case 0:if(end_tile == 9) { return 5; } else { return -1; }
	case 1:if(end_tile == 8) { return 5; } else if(end_tile == 10) { return 6; } else { return -1; }
	case 2:if(end_tile == 9) { return 6; } else if(end_tile == 11) { return 7; } else { return -1; }
	case 3:if(end_tile == 10) { return 7; } else { return -1; }
	case 4:if(end_tile == 13) { return 8; } else { return -1; }
	case 5:if(end_tile == 12) { return 8; } else if(end_tile == 14) { return 9; } else { return -1; }
	case 6:if(end_tile == 13) { return 9; } else if(end_tile == 15) { return 10; } else { return -1; }
	case 7:if(end_tile == 14) { return 10; } else { return -1; }
	case 8:if(end_tile == 1) { return 5; } else if(end_tile == 17) { return 13; } else { return -1; }
	case 9:if(end_tile == 0) { return 5; } else if(end_tile == 2) { return 6; }
			else if(end_tile == 16) { return 13; } else if(end_tile == 18) { return 14; } else { return -1; }
	case 10:if(end_tile == 1) { return 6; } else if(end_tile == 3) { return 7; }
			 else if(end_tile == 17) { return 14; } else if(end_tile == 19) { return 15; } else { return -1; }
	case 11:if(end_tile == 2) { return 7; } else if(end_tile == 18) { return 15; } else { return -1; }
	case 12:if(end_tile == 5) { return 8; } else if(end_tile == 21) { return 16; } else { return -1; }
	case 13:if(end_tile == 4) { return 8; } else if(end_tile == 6) { return 9; }
			 else if(end_tile == 20) { return 16; } else if(end_tile == 22) { return 17; } else { return -1; }
	case 14:if(end_tile == 5) { return 9; } else if(end_tile == 7) { return 10; }
			 else if(end_tile == 21) { return 17; } else if(end_tile == 23) { return 18; } else { return -1; }
	case 15:if(end_tile == 6) { return 10; } else if(end_tile == 22) { return 18; } else { return -1; }
	case 16:if(end_tile == 9) { return 13; } else if(end_tile == 25) { return 21; } else { return -1; }
	case 17:if(end_tile == 8) { return 13; } else if(end_tile == 10) { return 14; }
			 else if(end_tile == 24) { return 21; } else if(end_tile == 26) { return 22; } else { return -1; }
	case 18:if(end_tile == 9) { return 14; } else if(end_tile == 11) { return 15; }
			 else if(end_tile == 25) { return 22; } else if(end_tile == 27) { return 23; } else { return -1; }
	case 19:if(end_tile == 10) { return 15; } else if(end_tile == 26) { return 23; } else { return -1; }
	case 20:if(end_tile == 13) { return 16; } else if(end_tile == 29) { return 24; } else { return -1; }
	case 21:if(end_tile == 12) { return 16; } else if(end_tile == 14) { return 17; }
			 else if(end_tile == 28) { return 24; } else if(end_tile == 30) { return 25; } else { return -1; }
	case 22:if(end_tile == 13) { return 17; } else if(end_tile == 15) { return 18; }
			 else if(end_tile == 29) { return 25; } else if(end_tile == 31) { return 26; } else { return -1; }
	case 23:if(end_tile == 14) { return 18; } else if(end_tile == 30) { return 26; } else { return -1; }
	case 24:if(end_tile == 17) { return 21; } else { return -1; }
	case 25:if(end_tile == 16) { return 21; } else if(end_tile == 18) { return 22; } else { return -1; }
	case 26:if(end_tile == 17) { return 22; } else if(end_tile == 19) { return 23; } else { return -1; }
	case 27:if(end_tile == 18) { return 23; } else { return -1; }
	case 28:if(end_tile == 21) { return 24; } else { return -1; }
	case 29:if(end_tile == 20) { return 24; } else if(end_tile == 22) { return 25; } else { return -1; }
	case 30:if(end_tile == 21) { return 25; } else if(end_tile == 23) { return 26; } else { return -1; }
	case 31:if(end_tile == 22) { return 26; } else { return -1; }
	default:return -1;
	}
	return 0;
}

void Game::DestroyIt (const int which_tile) {
	for(int i = 0; i < _total_men; ++i) {
		if(players[i].GetSpecificTile () == which_tile && players[i].GetStatus() != PieceType::destroyed) {
			players[i].UpdateStatus (PieceType::destroyed);
			i >= 12 ? ++p1_destroyed : ++p2_destroyed;
			break;
		}
	}
}

void Game::DrawDestroyed (const int total_destroyed, const PlayerType which_player) {
	const int column_placement = (which_player == PlayerType::p2) ? 55 : 740;
	for(int i = 0; i < total_destroyed; ++i) {
		ply.Draw (gfx, Position (column_placement, 90 + (i * 35)), PieceType::man, which_player, true);
	}
}
