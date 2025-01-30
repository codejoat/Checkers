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
	position(116, 16) // Top left corner of board, to set board in center of 800 x 600 screen
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

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const Position mouse_position (wnd.mouse.GetPos ());
	auto now = std::chrono::steady_clock::now ();

	for(int i = 0; i < _total_men; ++i){

		const Position top_left = player[i].GetPosition () - 30;
		const Position bottom_right = player[i].GetPosition () + 30;

		if(mouse_position >= top_left && mouse_position <= bottom_right && !player[i].GetSelected()) {
			player[i].UpdateStatus (_hover);
			if(wnd.mouse.LeftIsPressed () && now - last_click_time > debounce_delay) {
				for(int j = 0; j < _total_men; ++j) {
					if(player[j].GetSelected ()) {
						player[j].SetSelected ();
						break;
					}
				}
				player[i].SetSelected ();
			}
		} else {
			player[i].UpdateStatus (_man);
		}
		for(int y = 0; y < _total_men; ++y) {
			if(mouse_position >= top_left && mouse_position <= bottom_right && player[y].GetSelected ()) {
				if(wnd.mouse.RightIsPressed ()) {
					player[y].SetSelected ();
				}
			}
		}
	}
	for(int i = 0; i < 32; ++i) {
		const Position tile_top_left = board.GetTileLocation (i) - 35;
		const Position tile_bottom_right = board.GetTileLocation (i) + 35;
		bool selected_on_board = false;
		
		for(int x = 0; x < _total_men; ++x) {
			if(player[x].GetSelected ()) {
				selected_on_board = true;
				break;
			}
		}
		if(mouse_position >= tile_top_left && mouse_position <= tile_bottom_right && !board.GetOccupied(i) && selected_on_board) {
			board.SetTileHover (i, true);
		} else {
			board.SetTileHover (i, false);
		}

		for(int k = 0; k < _total_men; ++k) {
			for(int j = 0; j < 32; ++j) {
				if(player[k].GetSelected ()) {
					if(board.GetTileHover (j) && wnd.mouse.LeftIsPressed ()) {
						last_click_time = now;
						player[k].SetSelected ();
						board.SetOccupied (player[k].GetSpecificTile (), p0);
						player[k].UpdatePosition (k, board.GetTileLocation (j));
						player[k].SetSpecificTile (j);
						if(k >= 12) {
							board.SetOccupied (j, p1);
						} else {
							board.SetOccupied (j, p2);
						}
					}
				}
			}
		}
	}
}

void Game::ComposeFrame ()
{
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
