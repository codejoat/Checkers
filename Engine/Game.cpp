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
	const Position mouse_position (wnd.mouse.GetPos ());
	auto now = std::chrono::steady_clock::now ();

	UpdatePlayerStatus (mouse_position, now);
	UpdateBoardHover (mouse_position);
	HandlePlayerMovement (mouse_position, now);
}

void Game::ComposeFrame () {
	DrawTable ();
	board.Draw (position);
	for(int i = 0; i < _total_men; ++i) {
		if(i >= _men_per_side) {
			players[i].Draw (gfx, players[i].GetPosition (), players[i].GetStatus (), PlayerType::p1);
		} else {
			players[i].Draw (gfx, players[i].GetPosition (), players[i].GetStatus (), PlayerType::p2);
		}
	}
	for(int i = 0; i < _total_men; ++i) {
		players[i].DrawSelectStatus (gfx, players[i].GetPosition (), players[i].GetSelectStatus ());
	}

	for(int i = 0; i < _total_moveable_tiles; ++i) {
		for(int j = 0; j < _total_men; ++j) {
			if(GetPossibleMoves (i) && (board.GetOccupiedBy (i) != PlayerType::p1) &&
				(board.GetOccupiedBy (i) != PlayerType::p2) && players[j].GetSelected ()) {
				DrawMoveableTile (board.GetTileLocation (i).x, board.GetTileLocation (i).y);
			}
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

		//if(players.GetStatus () == Destroyed) { continue }; Something like this.

		if(mouse_position >= top_left && mouse_position <= bottom_right && !players[i].GetSelected ()) {
			players[i].UpdateSelectStatus (PlayerStatus::hover);
		} else if(!players[i].GetSelected()) {
			players[i].UpdateSelectStatus (PlayerStatus::non);
		}
		
		if(players[i].GetSelectStatus () == PlayerStatus::hover && wnd.mouse.LeftIsPressed ()) {
			DeselectAllPlayers ();
			players[i].SetSelected ();
			players[i].UpdateSelectStatus (PlayerStatus::select);
			ResetCanMoveTo ();
			CanMoveTo (player_check, i, players[i].GetSpecificTile (), false); // TODO set boolean for players[i].GetStatus()
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
				players[i].SetSelected ();
				players[i].UpdatePosition (i, board.GetTileLocation (j));
				board.SetOccupiedBy (players[i].GetSpecificTile (), PlayerType::p0);
				players[i].SetSpecificTile (j);
				players[i].UpdateSelectStatus (PlayerStatus::non);
				board.SetOccupiedBy (j, (i >= 12 ? PlayerType::p1 : PlayerType::p2));
				ResetCanMoveTo ();
				++_move_counter;
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

void Game::CanMoveTo (const PlayerType which_player, const int which_man, const int which_tile, bool is_king) {
	const auto& moves = is_king ? king_moves : (which_player == PlayerType::p1 ? p1_moves : p2_moves);
	const int tile = players[which_man].GetSpecificTile ();
	if(tile < 0 || tile >= moves.size ()) return;

	for(int move : moves[tile]) {
		_can_move_to[move] = true;
	}
}

void Game::DrawMoveableTile (int board_x, int board_y) {
	gfx.DrawRing (board_x, board_y, 10, 12, Colors::Green);
}

bool Game::GetPossibleMoves (const int which_tile) const {
	return _can_move_to[which_tile];
}

void Game::ResetCanMoveTo () {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		_can_move_to[i] = false;
	}
}
