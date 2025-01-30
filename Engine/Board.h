#pragma once

#include "Position.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{
public:
	Board (Graphics& set_gfx);
	void Draw (const Position& position);
	Position GetTileLocation (const int tile_number) const;
	void SetTileLocation (const Position& tile_location, const int tile_number, bool for_locator);
	void SetOccupied (const int tile_to_set, int which_player);
	int GetOccupied (const int which_tile) const;
	void SetTileHover (const int which_tile, bool set_hover);
	bool GetTileHover (const int which_tile) const;


private:
	static constexpr int tile_dimension = 70;
	static constexpr int n_tiles = 64;
	static constexpr int n_black_tiles = 32;
	static constexpr int tiles_per_row = 8;
	static constexpr int padding = 1;
	Position build_board[n_tiles];
	Position tile_locator[n_black_tiles];
	int occupied[n_black_tiles] = { 0 }; // 0 == not, 1 == p1, 2 == p2
	Graphics& gfx;
	bool tile_hover[32] = { false };
};

