#include "Players.h"

void Players::Draw (Graphics& gfx, Location& loc, const int which_player, const int status) const
{
	switch(which_player) {
	case 1: gfx.DrawCircle (loc.x, loc.y, radius, Color (0, 0, 0));
		gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (5, 5, 5)); break;
	case 2: gfx.DrawCircle (loc.x, loc.y, radius, Color (185, 0, 0)); 
		gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (165, 10, 10)); break;
	default: gfx.DrawCircle (loc.x, loc.y, radius, Color (105, 105, 105));
	}

	switch(status) {
	case man: break;
	case hover: gfx.DrawRing (loc.x, loc.y, 28, 30, Colors::Yellow); break;
	case select: gfx.DrawRing (loc.x, loc.y, 28, 30, Colors::Cyan); break;
	case king: gfx.DrawRectangle (loc.x - 14, loc.y - 14, 28, 28, Color(150, 150, 150)); break;
	default: gfx.DrawCircle (loc.x, loc.y, radius / 2, Color (105, 105, 105));
	}
	
}

void Players::Update (const Location& new_location, const int new_status)
{
	location = new_location;
	status = new_status;
}

int Players::GetStatus () const
{
	return status;
}

Location Players::GetLocation (const Board& board, const int which_man) const
{
	Location location = board.GetTileLocation (which_man);
	return Location (location);
}
