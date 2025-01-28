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
	location(116, 16) // Top left corner of board, to set board in center of 800 x 600 screen
{
	for(int i = 0; i < 12; ++i) {
		player1_men[i].Update (board.GetTileLocation (i + 20), _man);
		player2_men[i].Update (board.GetTileLocation (i), _man);
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
	for(int i = 0; i < 12; i++) {
		const Location player1 = player1_men[i].GetLocation (board, i + 20);
		const Location player2 = player2_men[i].GetLocation (board, i);
		const Location mouse_position(wnd.mouse.GetPos());
		
		Location top_left1 = player1 - 24;
		Location bottom_right1 = player1 + 24;
		if(mouse_position >= top_left1 && mouse_position <= bottom_right1) {
			player1_men[i].Update (player1, _hover);
		} else {
			player1_men[i].Update (player1, _man);
		}

		Location top_left2 = player2 - 24;
		Location bottom_right2 = player2 + 24;
		if(mouse_position >= top_left2 && mouse_position <= bottom_right2) {
			player2_men[i].Update (player2, _hover);
		} else {
			player2_men[i].Update (player2, _man);
		}
	}
}

void Game::ComposeFrame ()
{
	board.Draw (location);	

	for(int i = 0; i < 12; ++i) {
		player1_men[i].Draw (gfx, board.GetTileLocation (i + 20), p1, player1_men[i].GetStatus ());
		player2_men[i].Draw (gfx, board.GetTileLocation (i), p2, player2_men[i].GetStatus ());
	}
}