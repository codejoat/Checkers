#include "Players.h"

//////////////////// PLAYER 1 //////////////////////

void Players::Player1Draw (Graphics& gfx, Location& loc) const
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (0, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (5, 5, 5));
	if(is_selected) {
		gfx.DrawRing (loc.x, loc.y, radius - 12, radius - 10, Colors::Yellow);
	}
	
}

//////////////////// PLAYER 2 //////////////////////

void Players::Player2Draw (Graphics& gfx, Location& loc) const
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (185, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (165, 10, 10));
	if(is_selected) {
		gfx.DrawRing (loc.x, loc.y, radius - 12, radius - 10, Colors::Yellow);
	}
	
}

Players::Players (Board& set_brd)
	:
	brd(set_brd)
{
}

void Players::Select ()
{
	if(!is_selected) {
		is_selected = true;
	}
}

Location Players::GetCoordinates (const int tile_number) const
{
	return Location (brd.GetTileLocation(tile_number));
}

