#include "Players.h"

void Players::Draw (Graphics& gfx, Position& position, const int which_player, const int status) const
{
	switch(which_player) {
	case 1: gfx.DrawCircle (position.x, position.y, radius, Color (0, 0, 0));
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (5, 5, 5)); break;
	case 2: gfx.DrawCircle (position.x, position.y, radius, Color (185, 0, 0)); 
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (165, 10, 10)); break;
	default: gfx.DrawCircle (position.x, position.y, radius, Color (105, 105, 105));
	}

	switch(status) {
	case man: break;
	case hover: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Yellow); break;
	case select: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Cyan); break;
	case king: gfx.DrawRectangle (position.x - 14, position.y - 14, 28, 28, Color(150, 150, 150)); break;
	default: gfx.DrawCircle (position.x, position.y, radius / 2, Color (105, 105, 105));
	}
	
}

void Players::Update (const Position& new_position, const int new_status)
{
	position = new_position;
	status = new_status;
	if(new_status == select) {
		is_selected = true;
	} else {
		is_selected = false;
	}
}

int Players::GetStatus () const
{
	return status;
}

Position Players::GetLocation (const Board& board, const int which_man) const
{
	Position position = board.GetTileLocation (which_man);
	return Position (position);
}

bool Players::IsSelected () const
{
	return is_selected;
}
