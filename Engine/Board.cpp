#include "Board.h"

Board::Board (Graphics& set_gfx)
	:
	gfx(set_gfx)
{
	// Build board and set all locations to center of squares
	int tile_counter = 0;
	int pattern_counter = 0;
	int black_tile_counter = 0;
	Position position = { 116, 16 };
	for(int y = position.y; y < position.y + tile_dimension * tiles_per_row; y += tile_dimension + padding) {
		for(int x = position.x; x < position.x + tile_dimension * tiles_per_row; x += tile_dimension + padding) {
			SetTileLocation (Position (x + tile_dimension / 2, y + tile_dimension / 2), tile_counter, false);
			++tile_counter;
			if(pattern_counter % 2 == 1) {
				SetTileLocation (Position (x + tile_dimension / 2, y + tile_dimension / 2), black_tile_counter, true);
				++black_tile_counter;
			}
			++pattern_counter;
		}
		++pattern_counter;
	}
}

void Board::Draw (const Position& position)
{
	// Draw the checker pattern // The pattern loop is only there to ++end_of_row, else you get stripes, not checkers
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

	// Draw a border with what looks like worn corners and a crease in the middle
	for(int y = position.y - 5; y < position.y + 12 + tile_dimension * tiles_per_row; ++y) {
		for(int x = position.x - 5; x < position.x + 12 + tile_dimension * tiles_per_row; ++x) {
			if(y < position.y - 1 || y > position.y + 7 + tile_dimension * tiles_per_row || x < position.x - 1 || x > position.x + 7 + tile_dimension * 8) {
				if(y < position.y - 1 && x < position.x - 1 ||
					y < position.y - 1 && x > position.x + 7 + tile_dimension * tiles_per_row ||
					y > position.y + 7 + tile_dimension * tiles_per_row && x < position.x - 1 ||
					y > position.y + 7 + tile_dimension * tiles_per_row && x > position.x + 7 + tile_dimension * tiles_per_row ||
					y > position.y + 1 + tile_dimension * tiles_per_row / 2 && y < position.y + 5 + tile_dimension * tiles_per_row / 2) {
					gfx.PutPixel (x, y, Color (65, 0, 0));
				} else {
					gfx.PutPixel (x, y, Color (95, 0, 15));
				}
				
			}
		}
	}
}

Position Board::GetTileLocation (const int tile_number) const
{
	return Position (tile_locator[tile_number].x, tile_locator[tile_number].y);
}

void Board::SetTileLocation (const Position& tile_location, const int tile_number, bool for_locator)
{
	if(!for_locator) {
		build_board[tile_number] = tile_location;
	} else {
		tile_locator[tile_number] = tile_location;
	}
}

void Board::SetOccupied (const int tile_to_set, int which_player)
{
	occupied[tile_to_set] = which_player;
}

int Board::GetOccupied (const int which_tile) const
{
	return occupied[which_tile];
}

void Board::SetTileHover (const int which_tile, bool set_hover)
{
	if(set_hover) {
		tile_hover[which_tile] = true;
	} else {
		tile_hover[which_tile] = false;
	}
}

bool Board::GetTileHover (const int which_tile) const
{
	return tile_hover[which_tile];
}
