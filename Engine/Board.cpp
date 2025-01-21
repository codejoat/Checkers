#include "Board.h"

Board::Board (Graphics& set_gfx)
	:
	gfx(set_gfx)
{
}

void Board::DrawCell (const Location& loc, Color c) const
{
	gfx.DrawRectanlge (loc.x * cell_dimension, loc.y * cell_dimension, cell_dimension, cell_dimension, c);
}

void Board::DrawBoard () const
{
	int counter = 0;
	for(int y = 0; y < GetGridHeight (); ++y) {
		for(int x = 0; x < GetGridWidth (); ++x) {
			Location loc = { x, y };
			if(counter % 2 == 0) {
				DrawCell (loc, Color(100, 0, 25));
			} else {
				DrawCell (loc, Color(25, 25, 25));
			}
			++counter;
		}
		++counter;
	}
}

int Board::GetGridWidth () const
{
	return width;
}

int Board::GetGridHeight () const
{
	return height;
}