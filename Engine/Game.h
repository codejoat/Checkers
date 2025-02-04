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
#include "Status.h"
#include <chrono>
#include <vector>
#include <array>

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
	bool PlayerTurn () const;
	void DrawTable ();
	void CanMoveTo (const PlayerType which_player, const int which_man, const int which_tile, bool is_king);
	void DrawMoveableTile (int board_x, int board_y);
	bool GetPossibleMoves (const int which_tile) const;
	void ResetCanMoveTo ();
	void CheckForKing ();
	bool HasMoves ();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr int _total_men = 24;
	static constexpr int _men_per_side = 12;
	static constexpr int _total_moveable_tiles = 32;
	static constexpr int _square_half_width = 35;
	static constexpr int _circle_half_width = 30;

	int _move_counter = 0;
	std::array<bool, _total_moveable_tiles> _can_move_to = { false };

	Board board;
	Position position;
	std::array<Players, _total_men> players;

	std::chrono::steady_clock::time_point _last_click_time;
	const std::chrono::milliseconds debounce_delay = std::chrono::milliseconds (200);


	// Define all potential moves for system to check
	const std::vector<std::vector<int>> p2_moves = {
		{4, 5}, {5, 6}, {6, 7}, {7},         // 0-3
		{8}, {8, 9}, {9, 10}, {10, 11},      // 4-7
		{12, 13}, {13, 14}, {14, 15}, {15},  // 8-11
		{16}, {16, 17}, {17, 18}, {18, 19},  // 12-15
		{20, 21}, {21, 22}, {22, 23}, {23},  // 16-19
		{24}, {24, 25}, {25, 26}, {26, 27},  // 20-23
		{28, 29}, {29, 30}, {30, 31}, {31},  // 24-27
		{24}, {24, 25}, {25, 26}, {26, 27}   // 28-31
	};
	
	const std::vector<std::vector<int>> p1_moves = {
		{4, 5}, {5, 6}, {6, 7}, {7},         // 0-3
		{0}, {0, 1}, {1, 2}, {2, 3},         // 4-7
		{4, 5}, {5, 6}, {6, 7}, {7},         // 8-11
		{8}, {8, 9}, {9, 10}, {10, 11},      // 12-15
		{12, 13}, {13, 14}, {14, 15}, {15},  // 16-19
		{16}, {16, 17}, {17, 18}, {18, 19},  // 20-23
		{20, 21}, {21, 22}, {22, 23}, {23},  // 24-27
		{24}, {24, 25}, {25, 26}, {26, 27}   // 28-31
		};

	const std::vector<std::vector<int>> king_moves = {
		{4, 5}, {5, 6}, {6, 7}, {7},                                     // 0-3
		{0, 8}, {0, 1, 8, 9}, {1, 2, 9, 10}, {2, 3, 10, 11},             // 4-7
		{4, 5, 12, 13}, {5, 6, 13, 14}, {6, 7, 14, 15}, {7, 15},         // 8-11
		{8, 16}, {8, 9, 16, 17}, {9, 10, 17, 18}, {10, 11, 18, 19},      // 12-15
		{12, 13, 20, 21}, {13, 14, 21, 22}, {14, 15, 22, 23}, {15, 23},  // 16-19
		{16, 24}, {16, 17, 24, 25}, {17, 18, 25, 26}, {18, 19, 26, 27},  // 20-23
		{20, 21, 28, 29}, {21, 22, 29, 30}, {22, 23, 30, 31}, {23, 31},  // 24-27
		{24}, {24, 25}, {25, 26}, {26, 27}                               // 28-31
	};
	/********************************/
};