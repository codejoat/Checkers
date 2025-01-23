#include "Players.h"

//////////////////// PLAYER 1 //////////////////////

void Players::Player1Draw (Graphics& gfx, Location& loc) const
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (0, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (5, 5, 5));	
}

//////////////////// PLAYER 2 //////////////////////

void Players::Player2Draw (Graphics& gfx, Location& loc) const
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (185, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (165, 10, 10));	
}

Players::Players (Board& set_brd)
	:
	brd(set_brd)
{
}

void Players::Select (Graphics& gfx, Location& loc) const
{
	gfx.DrawRing (loc.x, loc.y, radius - 12, radius - 10, Colors::Yellow);
}

Location Players::GetCoordinates (const int tile_number) const
{
	return Location (brd.GetTileLocation(tile_number));
}

