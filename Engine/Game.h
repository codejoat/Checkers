/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Colors.h"
#include "Board.h"
#include "Players.h"
#include "Position.h"
#include <chrono>

class Game {
public:
	Game (class MainWindow& wnd);
	Game (const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go ();
private:
	void ComposeFrame ();
	void UpdateModel ();
	/********************************/
	/*  User Functions              */
	void UpdatePlayerStatus (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now);
	void HandlePlayerMovement (const Position& mouse_position, const std::chrono::time_point<std::chrono::steady_clock>& now);
	void UpdateBoardHover (const Position& mouse_position);
	bool IsPlayerSelected () const;
	void DeselectAllPlayers ();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr int _total_men = 24;
	static constexpr int _men_per_side = 12;
	static constexpr int _total_moveable_tiles = 32;
	static constexpr int square_half_width = 35;
	static constexpr int circle_half_width = 30;
	static constexpr int p0 = 0;
	static constexpr int p1 = 1;
	static constexpr int p2 = 2;

	static constexpr int _man = 0;
	static constexpr int _king = 1;
	static constexpr int _hover = 2;
	static constexpr int _select = 3;


	Board board;
	Position position;

	Players player[_total_men];

	std::chrono::steady_clock::time_point last_click_time;
	const std::chrono::milliseconds debounce_delay = std::chrono::milliseconds (1250);
	/********************************/
};