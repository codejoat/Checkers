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
	brd(gfx)
{
	int tile_counter = 0;
	int black_tile_counter = 0;
	Location loc = { 116, 16 };
	for(int y = loc.y; y < loc.y + 8 + tile_dims * 8; y += tile_dims + 1) {
		for(int x = loc.x; x < loc.x + 8 + tile_dims * 8; x += tile_dims + 1) {
			if(tile_counter % 2 == 1) {
				brd.SetTileLocation (Location(x + tile_dims / 2, y + tile_dims / 2), black_tile_counter);
				black_tile_counter++;
			}
			++tile_counter;
		}
		++tile_counter;
	}

	for(int i = 0; i < 12; ++i) {
		player2[i].Player2SetLocation (i);
		player1[i].Player1SetLocation (i + 20);
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
	if(wnd.kbd.KeyIsPressed (VK_CONTROL)) {
		player1[0].Select ();
	}
}

void Game::ComposeFrame()
{	
	Location loc = { 116, 16 };
	brd.DrawBoard (loc);

	for(int i = 0; i < 12; i++) {
		player2[i].Player2Draw (gfx, brd.GetTileLocation(player2[i].PLayer2GetLocation()));
		player1[i].Player1Draw (gfx, brd.GetTileLocation(player1[i].PLayer2GetLocation()));
	}
	
}
