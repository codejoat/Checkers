#include "Players.h"

Players::Players (const Position& set_position)
	:
	position (set_position) { }

void Players::Draw (Graphics& gfx, const Position& position, const PieceType status, const PlayerType which_player, const bool captured) const {
	const int total_radius = captured ? radius / 2 : radius;
	switch(which_player) {
	case PlayerType::p1: gfx.DrawCircle (position.x, position.y, total_radius, Color (0, 0, 0));
		gfx.DrawCircle (position.x, position.y, total_radius - 5, Color (5, 5, 5)); break;
	case PlayerType::p2: gfx.DrawCircle (position.x, position.y, total_radius, Color (185, 0, 0));
		gfx.DrawCircle (position.x, position.y, total_radius - 5, Color (165, 10, 10)); break;
	default:break;
	}

	switch(status) {
	case PieceType::man: break;
	case PieceType::king: 
		switch(which_player) {
		case PlayerType::p1: DrawCrown (gfx, Position (position.x - 8, position.y - 5), Colors::Magenta); break;
		case PlayerType::p2: DrawCrown (gfx, Position (position.x - 8, position.y - 5), Colors::Yellow); break;
		}
	default:break;
	}
}

void Players::DrawSelectStatus (Graphics& gfx, const Position& position, const PlayerStatus select_status) const { 
	switch(select_status) {
	case PlayerStatus::non:break;
	case PlayerStatus::hover: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Gray); break;
	case PlayerStatus::select: gfx.DrawRing (position.x, position.y, 28, 30, Colors::Green); break;
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

void Players::DrawCrown (Graphics& gfx, Position& position, Color c) const {
	gfx.PutPixel (position.x + 8, position.y + 0, Colors::Gray);
	gfx.PutPixel (position.x + 9, position.y + 0, Colors::Gray);


	gfx.PutPixel (position.x +  7, position.y + 1, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 1, c);
	gfx.PutPixel (position.x +  9, position.y + 1, c);
	gfx.PutPixel (position.x + 10, position.y + 1, Colors::Gray);


	gfx.PutPixel (position.x +  7, position.y + 2, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 2, c);
	gfx.PutPixel (position.x +  9, position.y + 2, c);
	gfx.PutPixel (position.x + 10, position.y + 2, Colors::Gray);

	gfx.PutPixel (position.x +  1, position.y + 3, Colors::Gray);
	gfx.PutPixel (position.x +  2, position.y + 3, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 3, Colors::Gray);
	gfx.PutPixel (position.x +  9, position.y + 3, Colors::Gray);
	gfx.PutPixel (position.x + 15, position.y + 3, Colors::Gray);
	gfx.PutPixel (position.x + 16, position.y + 3, Colors::Gray);

	gfx.PutPixel (position.x +  0, position.y + 4, Colors::Gray);
	gfx.PutPixel (position.x +  1, position.y + 4, c);
	gfx.PutPixel (position.x +  2, position.y + 4, c);
	gfx.PutPixel (position.x +  3, position.y + 4, Colors::Gray);
	gfx.PutPixel (position.x +  7, position.y + 4, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 4, c);
	gfx.PutPixel (position.x +  9, position.y + 4, c);
	gfx.PutPixel (position.x + 10, position.y + 4, Colors::Gray);
	gfx.PutPixel (position.x + 14, position.y + 4, Colors::Gray);
	gfx.PutPixel (position.x + 15, position.y + 4, c);
	gfx.PutPixel (position.x + 16, position.y + 4, c);
	gfx.PutPixel (position.x + 17, position.y + 4, Colors::Gray);

	gfx.PutPixel (position.x +  0, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x +  1, position.y + 5, c);
	gfx.PutPixel (position.x +  2, position.y + 5, c);
	gfx.PutPixel (position.x +  3, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x +  6, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x +  7, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 5, c);
	gfx.PutPixel (position.x +  9, position.y + 5, c);
	gfx.PutPixel (position.x + 10, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x + 11, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x + 14, position.y + 5, Colors::Gray);
	gfx.PutPixel (position.x + 15, position.y + 5, c);
	gfx.PutPixel (position.x + 16, position.y + 5, c);
	gfx.PutPixel (position.x + 17, position.y + 5, Colors::Gray);

	gfx.PutPixel (position.x +  0, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x +  1, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x +  2, position.y + 6, c);
	gfx.PutPixel (position.x +  3, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x +  5, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x +  6, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x +  7, position.y + 6, c);
	gfx.PutPixel (position.x +  8, position.y + 6, c);
	gfx.PutPixel (position.x +  9, position.y + 6, c);
	gfx.PutPixel (position.x + 10, position.y + 6, c);
	gfx.PutPixel (position.x + 11, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x + 12, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x + 14, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x + 15, position.y + 6, c);
	gfx.PutPixel (position.x + 16, position.y + 6, Colors::Gray);
	gfx.PutPixel (position.x + 17, position.y + 6, Colors::Gray);

	gfx.PutPixel (position.x +  1, position.y + 7, Colors::Gray);
	gfx.PutPixel (position.x +  2, position.y + 7, c);
	gfx.PutPixel (position.x +  3, position.y + 7, c);
	gfx.PutPixel (position.x +  4, position.y + 7, Colors::Gray);
	gfx.PutPixel (position.x +  5, position.y + 7, Colors::Gray);
	gfx.PutPixel (position.x +  6, position.y + 7, c);
	gfx.PutPixel (position.x +  7, position.y + 7, c);
	gfx.PutPixel (position.x +  8, position.y + 7, c);
	gfx.PutPixel (position.x +  9, position.y + 7, c);
	gfx.PutPixel (position.x + 10, position.y + 7, c);
	gfx.PutPixel (position.x + 11, position.y + 7, c);
	gfx.PutPixel (position.x + 12, position.y + 7, Colors::Gray);
	gfx.PutPixel (position.x + 13, position.y + 7, Colors::Gray);
	gfx.PutPixel (position.x + 14, position.y + 7, c);
	gfx.PutPixel (position.x + 15, position.y + 7, c);
	gfx.PutPixel (position.x + 16, position.y + 7, Colors::Gray);

	gfx.PutPixel (position.x +  2, position.y + 8, Colors::Gray);
	gfx.PutPixel (position.x +  3, position.y + 8, c);
	gfx.PutPixel (position.x +  4, position.y + 8, c);
	gfx.PutPixel (position.x +  5, position.y + 8, c);
	gfx.PutPixel (position.x +  6, position.y + 8, c);
	gfx.PutPixel (position.x +  7, position.y + 8, c);
	gfx.PutPixel (position.x +  8, position.y + 8, c);
	gfx.PutPixel (position.x +  9, position.y + 8, c);
	gfx.PutPixel (position.x + 10, position.y + 8, c);
	gfx.PutPixel (position.x + 11, position.y + 8, c);
	gfx.PutPixel (position.x + 12, position.y + 8, c);
	gfx.PutPixel (position.x + 13, position.y + 8, c);
	gfx.PutPixel (position.x + 14, position.y + 8, c);
	gfx.PutPixel (position.x + 15, position.y + 8, Colors::Gray);

	gfx.PutPixel (position.x +  2, position.y + 9, Colors::Gray);
	gfx.PutPixel (position.x +  3, position.y + 9, c);
	gfx.PutPixel (position.x +  4, position.y + 9, c);
	gfx.PutPixel (position.x +  5, position.y + 9, c);
	gfx.PutPixel (position.x +  6, position.y + 9, c);
	gfx.PutPixel (position.x +  7, position.y + 9, c);
	gfx.PutPixel (position.x +  8, position.y + 9, c);
	gfx.PutPixel (position.x +  9, position.y + 9, c);
	gfx.PutPixel (position.x + 10, position.y + 9, c);
	gfx.PutPixel (position.x + 11, position.y + 9, c);
	gfx.PutPixel (position.x + 12, position.y + 9, c);
	gfx.PutPixel (position.x + 13, position.y + 9, c);
	gfx.PutPixel (position.x + 14, position.y + 9, c);
	gfx.PutPixel (position.x + 15, position.y + 9, Colors::Gray);

	gfx.PutPixel (position.x +  3, position.y + 10, Colors::Gray);
	gfx.PutPixel (position.x +  4, position.y + 10, c);
	gfx.PutPixel (position.x +  5, position.y + 10, c);
	gfx.PutPixel (position.x +  6, position.y + 10, c);
	gfx.PutPixel (position.x +  7, position.y + 10, c);
	gfx.PutPixel (position.x +  8, position.y + 10, c);
	gfx.PutPixel (position.x +  9, position.y + 10, c);
	gfx.PutPixel (position.x + 10, position.y + 10, c);
	gfx.PutPixel (position.x + 11, position.y + 10, c);
	gfx.PutPixel (position.x + 12, position.y + 10, c);
	gfx.PutPixel (position.x + 13, position.y + 10, c);
	gfx.PutPixel (position.x + 14, position.y + 10, Colors::Gray);

	gfx.PutPixel (position.x +  3, position.y + 11, Colors::Gray);
	gfx.PutPixel (position.x +  4, position.y + 11, Colors::Gray);
	gfx.PutPixel (position.x +  5, position.y + 11, c);
	gfx.PutPixel (position.x +  6, position.y + 11, c);
	gfx.PutPixel (position.x +  7, position.y + 11, c);
	gfx.PutPixel (position.x +  8, position.y + 11, c);
	gfx.PutPixel (position.x +  9, position.y + 11, c);
	gfx.PutPixel (position.x + 10, position.y + 11, c);
	gfx.PutPixel (position.x + 11, position.y + 11, c);
	gfx.PutPixel (position.x + 12, position.y + 11, c);
	gfx.PutPixel (position.x + 13, position.y + 11, Colors::Gray);
	gfx.PutPixel (position.x + 14, position.y + 11, Colors::Gray);

	gfx.PutPixel (position.x +  4, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x +  5, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x +  6, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x +  7, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x +  8, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x +  9, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x + 10, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x + 11, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x + 12, position.y + 12, Colors::Gray);
	gfx.PutPixel (position.x + 13, position.y + 12, Colors::Gray);
}

