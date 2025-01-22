#include "Players.h"

//////////////////// PLAYER 1 //////////////////////

void Players::Player1Draw (Graphics& gfx, Location& loc)
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (0, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (5, 5, 5));
	if(is_selected) {
		gfx.DrawRing (loc.x, loc.y, radius - 12, radius - 10, Colors::Yellow);
	}
	
}

void Players::Player1SetLocation (const int set_location)
{
	location = set_location;
}

int Players::Player1GetLocation () const
{
	return location;
}


//////////////////// PLAYER 2 //////////////////////

void Players::Player2Draw (Graphics& gfx, Location& loc)
{
	gfx.DrawCircle (loc.x, loc.y, radius, Color (185, 0, 0));
	gfx.DrawCircle (loc.x, loc.y, radius - 5, Color (165, 10, 10));
	if(is_selected) {
		gfx.DrawRing (loc.x, loc.y, radius - 12, radius - 10, Colors::Yellow);
	}
	
}

void Players::Player2SetLocation (const int set_location)
{
	location = set_location;
}

int Players::PLayer2GetLocation () const
{
	return location;
}

void Players::Select ()
{
	if(!is_selected) {
		is_selected = true;
	} else {
		is_selected = false;
	}
}

