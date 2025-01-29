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
	for(int i = 0; i < 12; i++) {
		const Position position_p1 = player1[i].GetLocation (board, i + 20);
		const Position mouse_position(wnd.mouse.GetPos());
		
		Position top_left1 = position_p1 - 30;
		Position bottom_right1 = position_p1 + 30;
		if(mouse_position >= top_left1 && mouse_position <= bottom_right1 && !player1[i].IsSelected()) {
			player1[i].Update (position_p1, _hover);
		} else if(!player1[i].IsSelected ()) {
			player1[i].Update (position_p1, _man);
		}
		if(player1[i].GetStatus () == _hover && wnd.mouse.LeftIsPressed ()) {
			for(int j = 0; j < 12; ++j) {
				if(player1[j].GetStatus () == _select) {
					player1[j].Update (position_p1, _man);
				}
			}
			player1[i].Update (position_p1, _select);
		}
		if(player1[i].GetStatus () == _select && position_p1 != mouse_position) {
			if(wnd.mouse.RightIsPressed ()) {
				player1[i].Update (board.GetTileLocation(16), _man);
			}
		}
	}

	
}

void Game::ComposeFrame ()
{
	board.Draw (position);	

	for(int i = 0; i < 12; ++i) {
		player1[i].Draw (gfx, board.GetTileLocation (i + 20), p1, player1[i].GetStatus ());

	}
}