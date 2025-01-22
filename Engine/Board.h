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
	void SetTileLocation (const Location& loc, const int tile_number);

private:
	static constexpr int tile_dimension = 70;
	Location tile_locator[32];
	Graphics& gfx;
};

