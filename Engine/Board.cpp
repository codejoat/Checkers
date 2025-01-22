#include "Board.h"

Board::Board (Graphics& set_gfx)
	:
	gfx(set_gfx)
{
}

void Board::DrawBoard (Location& loc)
{
	int tile_counter = 0;
	for(int y = loc.y; y < loc.y + 8 + tile_dimension * 8; y += tile_dimension + 1) {
		for(int x = loc.x; x < loc.x + 8 + tile_dimension * 8; x += tile_dimension + 1) {
			if(tile_counter % 2 == 0) {
				gfx.DrawRectangle (x, y, tile_dimension, tile_dimension, Color (100, 0, 25));
			} else {
				gfx.DrawRectangle (x, y, tile_dimension, tile_dimension, Color (25, 25, 25));
			}
			++tile_counter;
		}
		++tile_counter;
	}

	for(int y = loc.y - 5; y < loc.y + 8 + 5 + tile_dimension * 8; ++y) {
		for(int x = loc.x - 5; x < loc.x + 8 + 5 + tile_dimension * 8; ++x) {
			if(y < loc.y - 1 || y > loc.y + 7 + tile_dimension * 8 || x < loc.x - 1 || x > loc.x + 7 + tile_dimension * 8) {
				gfx.PutPixel (x, y, Color (100, 0, 25));
			}
		}
	}
}

Location Board::GetTileLocation (const int tile_number) const
{
	return Location (tile_locator[tile_number].x, tile_locator[tile_number].y);
}

void Board::SetTileLocation (const Location& loc, const int tile_number)
{
	tile_locator[tile_number].x = loc.x;
	tile_locator[tile_number].y = loc.y;
}

