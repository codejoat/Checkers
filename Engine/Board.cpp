#include "Board.h"

Board::Board (Graphics& set_gfx)
	:
	gfx(set_gfx)
{
	int tile_counter = 0;
	int pattern_counter = 0;
	int black_tile_counter = 0;
	Location loc = { 116, 16 };
	for(int y = loc.y; y < loc.y + tile_dimension * tiles_per_row; y += tile_dimension + padding) {
		for(int x = loc.x; x < loc.x + tile_dimension * tiles_per_row; x += tile_dimension + padding) {
			SetTileLocation (Location (x + tile_dimension / 2, y + tile_dimension / 2), tile_counter, false);
			++tile_counter;
			if(pattern_counter % 2 == 1) {
				SetTileLocation (Location (x + tile_dimension / 2, y + tile_dimension / 2), black_tile_counter, true);
				++black_tile_counter;
			}
			++pattern_counter;
		}
		++pattern_counter;
	}
}

void Board::DrawBoard (Location& loc)
{
	for(int pattern = 0; pattern < tiles_per_row; ++pattern) {
		for(int i = 0; i < tiles_per_row; ++i) {
			int x = build_board[i + pattern * tiles_per_row].x - tile_dimension / 2;
			int y = build_board[i + pattern * tiles_per_row].y - tile_dimension / 2;

			if((i + pattern) % 2 == 0) {
				gfx.DrawRectangle (x, y, tile_dimension, tile_dimension, Color (100, 0, 25));
			} else {
				gfx.DrawRectangle (x, y, tile_dimension, tile_dimension, Color (20, 20, 20));
			}
		}
	}

	for(int y = loc.y - 5; y < loc.y + 12 + tile_dimension * tiles_per_row; ++y) {
		for(int x = loc.x - 5; x < loc.x + 12 + tile_dimension * tiles_per_row; ++x) {
			if(y < loc.y - 1 || y > loc.y + 7 + tile_dimension * tiles_per_row || x < loc.x - 1 || x > loc.x + 7 + tile_dimension * 8) {
				if(y < loc.y - 1 && x < loc.x - 1 ||
					y < loc.y - 1 && x > loc.x + 7 + tile_dimension * tiles_per_row ||
					y > loc.y + 7 + tile_dimension * tiles_per_row && x < loc.x - 1 ||
					y > loc.y + 7 + tile_dimension * tiles_per_row && x > loc.x + 7 + tile_dimension * tiles_per_row ||
					y > loc.y + 1 + tile_dimension * tiles_per_row / 2 && y < loc.y + 5 + tile_dimension * tiles_per_row / 2) {
					gfx.PutPixel (x, y, Color (65, 0, 0));
				} else {
					gfx.PutPixel (x, y, Color (95, 0, 15));
				}
				
			}
		}
	}
}

Location Board::GetTileLocation (const int tile_number) const
{
	return Location (tile_locator[tile_number].x, tile_locator[tile_number].y);
}

void Board::SetTileLocation (const Location& loc, const int tile_number, bool for_locator)
{
	if(!for_locator) {
		build_board[tile_number].x = loc.x;
		build_board[tile_number].y = loc.y;
	} else {
		tile_locator[tile_number].x = loc.x;
		tile_locator[tile_number].y = loc.y;
	}
}