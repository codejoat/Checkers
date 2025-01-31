#pragma once

#include "Position.h"
#include "Graphics.h"
#include "Board.h"
#include "Mouse.h"

class Players {

private:
	Position position;
	int status = man;
	int specific_tile;

public:
	Players () = default;
	Players (const Position& set_position);
	void Draw (Graphics& gfx, const Position& position, const int status, const int which_player) const;
	void InitPosition (const Position& set_position);
	void InitStatus ();
	void UpdateStatus (const int new_status);
	void UpdatePosition (const int which_man, const Position& new_position);
	Position GetPosition () const;
	int GetStatus () const;
	void SetSelected ();
	bool GetSelected () const;
	void SetSpecificTile (const int set_tile);
	int GetSpecificTile () const;

private:
	static constexpr int man = 0;
	static constexpr int king = 1;
	static constexpr int hover = 2;
	static constexpr int select = 3;
	static constexpr int radius = 30;
	static constexpr int total_men = 24;
	static constexpr int men_per_side = 12;

	bool is_selected = false;
	//bool destroyed = false;
};