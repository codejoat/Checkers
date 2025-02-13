#pragma once

#include "Position.h"
#include "Graphics.h"
#include "Board.h"
#include "Mouse.h"
#include "Status.h"

class Players {
private:
	Position position = { 69, 420 };
	PieceType status = PieceType::man;
	PlayerStatus select_status = PlayerStatus::non;
	int specific_tile = 0;
	bool is_selected = false;

public:
	Players () = default;
	Players (const Position& set_position);
	void Draw (Graphics& gfx, const Position& position, const PieceType status, const PlayerType which_player, const bool captured) const;
	void DrawSelectStatus (Graphics& gfx, const Position& position, const PlayerStatus select_status) const;
	void DrawCrown (Graphics& gfx, Position& position, Color c) const;
	void InitPosition (const Position& set_position);
	void InitStatus ();
	void UpdateStatus (const PieceType new_status);
	void UpdateSelectStatus (const PlayerStatus new_select_status);
	void UpdatePosition (const int which_man, const Position& new_position);
	void SetSelected ();
	void SetSpecificTile (const int set_tile);
	
	bool GetSelected () const;
	int GetSpecificTile () const;
	
	Position GetPosition () const;
	PieceType GetStatus () const;
	PlayerStatus GetSelectStatus () const;

private:
	static constexpr int radius = 30;
	static constexpr int total_men = 24;
	static constexpr int men_per_side = 12;
};