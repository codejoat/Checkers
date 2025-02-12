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
#include <cmath>
#include <fstream>
#include <iostream>

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
	void DrawMoveableTile (int board_x, int board_y, bool additional);
	bool GetPossibleMoves (const int which_tile) const;
	bool GetAdditionalMoves (const int which_tile) const;
	void ParityMoves ();
	void ResetCanMoveTo ();
	void CheckForKing ();
	bool HasMoves ();
	int GetJumpTile (const int start_tile, const int end_tile) const;
	void DestroyIt (const int which_tile);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr int move_nine = 9;
	static constexpr int move_seven = 7;
	static constexpr int _total_men = 24;
	static constexpr int _men_per_side = 12;
	static constexpr int _total_moveable_tiles = 32;
	static constexpr int _square_half_width = 35;
	static constexpr int _circle_half_width = 30;

	int _move_counter = 0;
	bool jump_again = false;
	std::array<bool, _total_moveable_tiles> _can_move_to = { false };
	std::array<bool, _total_moveable_tiles> _additional_jumps = { false };

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

	// Define all potential jumps for system to check
	const std::vector<std::vector<int>> p2_jumps = {
		{9}, {8, 10 }, {9, 11 }, {10 },      // 0-3
		{13}, {12, 14}, {13, 15}, {14},      // 4-7
		{17}, {16, 18}, {17, 19}, {18},      // 8-11
		{21}, {20, 22}, {21, 23}, {22},      // 12-15
		{25}, {24, 26}, {25, 27}, {26},      // 16-19
		{29}, {28, 30}, {29, 31}, {30},      // 20-23
		{}, {}, {}, {},                      // 24-27
		{}, {}, {}, {}                       // 28-31
	};

	const std::vector<std::vector<int>> p1_jumps = {
		{}, {}, {}, {},                      // 0-3
		{}, {}, {}, {},                      // 4-7
		{1}, {0, 2}, {1, 3}, {2},            // 8-11
		{5}, {4, 6}, {5, 7}, {6},            // 12-15
		{9}, {8, 10}, {9, 11}, {10},         // 16-19
		{13}, {12, 14}, {13, 15}, {14},      // 20-23
		{17}, {16, 18}, {17, 19}, {18},      // 24-27
		{21}, {20, 22}, {21, 23}, {22}       // 28-31
	};

	const std::vector<std::vector<int>> king_jumps = {
		{9}, {8, 10}, {9, 11}, {10},                                     // 0-3
		{13}, {12, 14}, {13, 15}, {14},                                  // 4-7
		{1, 17}, {0, 2, 16, 18}, {1, 3, 17, 19}, {2, 18},                // 8-11
		{5, 21}, {4, 6, 20, 22}, {5, 7, 21, 23}, {6, 22},                // 12-15
		{9, 25}, {8, 10, 24, 26}, {9, 11, 25, 27}, {10, 26},             // 16-19
		{13, 29}, {12, 14, 28, 30}, {13, 15, 29, 31}, {14, 30},          // 20-23
		{17}, {16, 18}, {17, 19}, {18},                                  // 24-27
		{21}, {20, 22}, {21, 23}, {22}                                   // 28-31
	};
	/********************************/
};