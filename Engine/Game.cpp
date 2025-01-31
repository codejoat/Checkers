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
			player[i].InitPosition (board.GetTileLocation (i + 8));
			player[i].SetSpecificTile (i + 8);
			board.SetOccupied (i + 8, p1);
		} else {
			player[i].InitPosition (board.GetTileLocation (i));
			player[i].SetSpecificTile (i);
			board.SetOccupied (i, p2);
		}
		player[i].InitStatus ();
	}
}

void Game::Go () {
	gfx.BeginFrame ();
	UpdateModel ();
	ComposeFrame ();
	gfx.EndFrame ();
}

/////////////////////////////////////// MAIN WORK AREA //////////////////////////////////////////////////////////////////////////

void Game::UpdateModel () {
	const Position mouse_position (wnd.mouse.GetPos ());
	auto now = std::chrono::steady_clock::now ();

	UpdatePlayerStatus (mouse_position, now);
	UpdateBoardHover (mouse_position);
	HandlePlayerMovement (mouse_position, now);

}

void Game::ComposeFrame () {
	board.Draw (position);
	for(int i = 0; i < _total_men; ++i) {
		if(i >= _men_per_side) {
			player[i].Draw (gfx, player[i].GetPosition (), player[i].GetStatus (), p1);
		} else {
			player[i].Draw (gfx, player[i].GetPosition (), player[i].GetStatus (), p2);
		}
	}

	for(int i = 0; i < 32; ++i) {
		if(board.GetTileHover (i)) {
			gfx.DrawRing (board.GetTileLocation (i).x, board.GetTileLocation (i).y, 10, 12, Colors::White);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::UpdatePlayerStatus (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now) {
	for(int i = 0; i < _total_men; ++i) {
		const Position top_left = player[i].GetPosition () - circle_half_width;
		const Position bottom_right = player[i].GetPosition () + circle_half_width;

		if(mouse_position >= top_left && mouse_position <= bottom_right && !player[i].GetSelected ()) {
			player[i].UpdateStatus (_hover);
			if(wnd.mouse.LeftIsPressed () && now - last_click_time > debounce_delay) {
				DeselectAllPlayers ();
				player[i].SetSelected ();
			}
		} else {
			player[i].UpdateStatus (_man);
		}

		if(mouse_position >= top_left && mouse_position <= bottom_right && player[i].GetSelected ()) {
			if(wnd.mouse.RightIsPressed ()) {
				player[i].SetSelected ();
			}
		}
	}
}

void Game::HandlePlayerMovement (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now) {
	for(int i = 0; i < _total_men; ++i) {
		for(int j = 0; j < _total_moveable_tiles; ++j) {
			if(player[i].GetSelected () && board.GetTileHover (j) && wnd.mouse.LeftIsPressed ()) {
				last_click_time = now;
				player[i].SetSelected ();
				board.SetOccupied (player[i].GetSpecificTile (), p0);
				player[i].UpdatePosition (i, board.GetTileLocation (j));
				player[i].SetSpecificTile (j);
				board.SetOccupied (j, i >= 12 ? p1 : p2);
			}
		}
	}
}

void Game::UpdateBoardHover (const Position& mouse_position) {
	for(int i = 0; i < _total_moveable_tiles; ++i) {
		const Position top_left = board.GetTileLocation (i) - square_half_width;
		const Position bottom_right = board.GetTileLocation (i) + square_half_width;
		bool selected_on_board = IsPlayerSelected ();

		if(mouse_position >= top_left && mouse_position <= bottom_right && !board.GetOccupied (i) && selected_on_board) {
			board.SetTileHover (i, true);
		} else {
			board.SetTileHover (i, false);
		}
	}
}

bool Game::IsPlayerSelected () const {
	for(int i = 0; i < _total_men; ++i) {
		if(player[i].GetSelected ()) {
			return true;
		}
	}
	return false;
}

void Game::DeselectAllPlayers () { 
	for(int i = 0; i < _total_men; ++i) {
		if(player[i].GetSelected ()) {
			player[i].SetSelected ();
			break;
		}
	}
}