#pragma once

#include "Position.h"
#include "Graphics.h"
#include "Board.h"
#include "Mouse.h"

class Players {
	
private:
	Position position;

public:
	Players () = default;
	void Draw (Graphics& gfx, Position& position, const int which_player, const int status) const;
	void Update (const Position& new_location, const int new_status);
	int GetStatus () const;
	bool IsSelected () const;
	Position GetLocation (const Board& board, const int which_man) const;
	


private:
	static constexpr int man = 0;
	static constexpr int king = 1;
	static constexpr int hover = 2;
	static constexpr int select = 3;
	static constexpr int radius = 30;
	
	bool is_selected = false;
	bool destroyed = false;

	int status = man;
};