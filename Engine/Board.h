#pragma once

#include "Location.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{
public:
	Board (Graphics& set_gfx);
	void DrawBoard (Location& loc);
	Location GetTileLocation (const int tile_number) const;
	void SetTileLocation (const Location& loc, const int tile_number, bool for_locator);


private:
	static constexpr int tile_dimension = 70;
	static constexpr int total_tiles = 64;
	static constexpr int black_tiles = 32;
	static constexpr int tiles_per_row = 8;
	static constexpr int padding = 1;
	Location build_board[total_tiles];
	Location tile_locator[black_tiles];
	Graphics& gfx;
};

