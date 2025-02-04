#pragma once

#include "Position.h"
#include "Colors.h"
#include "Graphics.h"
#include "Status.h"

#include <array>

class Board {
public:
	Board (Graphics& set_gfx);
	void Draw (const Position& position);
	Position GetTileLocation (const int tile_number) const;
	void SetTileLocation (const Position& tile_location, const int tile_number, bool for_locator);
	void SetOccupiedBy (const int tile_to_set, PlayerType which_player);
	PlayerType GetOccupiedBy (const int which_tile) const;
	void SetTileHover (const int which_tile, bool set_hover);
	bool GetTileHover (const int which_tile) const;

private:
	static constexpr int tile_dimension = 70;
	static constexpr int n_black_tiles = 32;
	static constexpr int tiles_per_row = 8;
	static constexpr int n_tiles = 64;
	static constexpr int padding = 1;
	
	std::array<Position, n_tiles> build_board;
	std::array<Position, n_black_tiles> tile_locator;
	std::array<PlayerType, n_black_tiles> occupied_by = { PlayerType::p0 };
	std::array<bool, n_black_tiles> tile_hover = { false };
	
	Graphics& gfx;
};

