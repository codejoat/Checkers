#pragma once

#include "Location.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{
public:
	Board (Graphics& set_gfx);
	void Draw (const Location& loc);
	Location GetTileLocation (const int tile_number) const;
	void SetTileLocation (const Location& tile_location, const int tile_number, bool for_locator);
	void SetOccupied (const int tile_to_set, int which_player);


private:
	static constexpr int tile_dimension = 70;
	static constexpr int n_tiles = 64;
	static constexpr int n_black_tiles = 32;
	static constexpr int tiles_per_row = 8;
	static constexpr int padding = 1;
	Location build_board[n_tiles];
	Location tile_locator[n_black_tiles];
	int occupied[n_black_tiles] = { 0 }; // 0 == not, 1 == p1, 2 == p2
	Graphics& gfx;
};

