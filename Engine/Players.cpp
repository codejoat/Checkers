#include "Players.h"

Players::Players (const Position& set_position)
	:
	position (set_position) { }

void Players::Draw (Graphics& gfx, const Position& position, const int status, const int which_player) const {
	switch(which_player) {
	case 1: gfx.DrawCircle (position.x, position.y, radius, Color (0, 0, 0));
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (5, 5, 5)); break;
	case 2: gfx.DrawCircle (position.x, position.y, radius, Color (185, 0, 0));
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (165, 10, 10)); break;
	default: gfx.DrawCircle (position.x, position.y, radius, Color (105, 105, 105));
	}

	switch(status) {
	case man: break;
	case king: gfx.DrawRectangle (position.x - 14, position.y - 14, 28, 28, Color (150, 150, 150)); break;
	case hover: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Yellow); break;
	case select: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Cyan); break;
	default: gfx.DrawCircle (position.x, position.y, radius / 2, Color (105, 105, 105));
	}
}

void Players::InitPosition (const Position& set_position) {
	position = set_position;
}

void Players::InitStatus () {
	status = man;
}



void Players::UpdateStatus (const int new_status) {
	if(is_selected) {
		status = select;
	} else {
		status = new_status;
	}
}

void Players::UpdatePosition (const int which_man, const Position& new_position) {
	position = new_position;
}

int Players::GetStatus () const {
	return status;
}

void Players::SetSelected () {
	if(!is_selected) {
		is_selected = true;
	} else {
		is_selected = false;
	}
}

Position Players::GetPosition () const {
	return position;
}

bool Players::GetSelected () const {
	return is_selected;
}

void Players::SetSpecificTile (const int set_tile) {
	specific_tile = set_tile;
}

int Players::GetSpecificTile () const {
	return specific_tile;
}
