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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board(gfx)
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
}

void Game::ComposeFrame()
{
	board.DrawBoard ();

	// For setup
	// y moves by 70
	// x moves by 140
	// x spread is 560
	// y spread is 210


	int counter = 0;
	for(int y0 = 35; y0 < 245; y0 += 70) {
		if(counter % 2 == 0) {
			for(int x0 = 105; x0 < 665; x0 += 140) {
				gfx.DrawCircle (x0, y0, 30, Color(185, 0, 0));
				gfx.DrawCircle (x0, y0, 25, Color(165, 10, 10));
			}
		} else {
			for(int x0 = 35; x0 < 595; x0 += 140) {
				gfx.DrawCircle (x0, y0, 30, Color(185, 0, 0));
				gfx.DrawCircle (x0, y0, 25, Color (165, 10, 10));
			}
		}
		++counter;
	}

	counter = 0;
	for(int y1 = 385; y1 < 595; y1 += 70) {
		if(counter % 2 == 1) {
			for(int x1 = 105; x1 < 665; x1 += 140) {
				gfx.DrawCircle (x1, y1, 30, Colors::Black);
				gfx.DrawCircle (x1, y1, 25, Color (5, 5, 5));
			}
		} else {
			for(int x1 = 35; x1 < 595; x1 += 140) {
				gfx.DrawCircle (x1, y1, 30, Colors::Black);
				gfx.DrawCircle (x1, y1, 25, Color (5, 5, 5));
			}
		}
		++counter;
	}
	
}
