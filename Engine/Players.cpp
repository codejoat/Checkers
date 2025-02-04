#include "Players.h"

Players::Players (const Position& set_position)
	:
	position (set_position) { }

void Players::Draw (Graphics& gfx, const Position& position, const PieceType status, const PlayerType which_player) const {
	switch(which_player) {
	case PlayerType::p1: gfx.DrawCircle (position.x, position.y, radius, Color (0, 0, 0));
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (5, 5, 5)); break;
	case PlayerType::p2: gfx.DrawCircle (position.x, position.y, radius, Color (185, 0, 0));
		gfx.DrawCircle (position.x, position.y, radius - 5, Color (165, 10, 10)); break;
	default:break;
	}

	switch(status) {
	case PieceType::man: break;
	case PieceType::king: gfx.DrawRectangle (position.x - 14, position.y - 14, 28, 28, Color (150, 150, 150)); break;
	default:break;
	}
}

void Players::DrawSelectStatus (Graphics& gfx, const Position& position, const PlayerStatus select_status) const { 
	switch(select_status) {
	case PlayerStatus::non:break;
	case PlayerStatus::hover: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Yellow); break;
	case PlayerStatus::select: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Cyan); break;
	default:break;
	}
}

void Players::InitPosition (const Position& set_position) {
	position = set_position;
}

void Players::InitStatus () {
	status = PieceType::man;
}

void Players::UpdateStatus (const PieceType new_status) {
	status = new_status;
}

void Players::UpdateSelectStatus (const PlayerStatus new_select_status) {
	select_status = new_select_status;
}

void Players::UpdatePosition (const int which_man, const Position& new_position) {
	position = new_position;
}

void Players::SetSpecificTile (const int set_tile) {
	specific_tile = set_tile;
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

PieceType Players::GetStatus () const {
	return status;
}

PlayerStatus Players::GetSelectStatus () const {
	return select_status;
}

bool Players::GetSelected () const {
	return is_selected;
}

int Players::GetSpecificTile () const {
	return specific_tile;
}

