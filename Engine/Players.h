#pragma once

#include "Location.h"
#include "Graphics.h"
#include "Board.h"
#include "Mouse.h"

class Players
{
public: 
	Players (Board& set_brd);
	void Player1Draw (Graphics& gfx, Location& loc) const;
	void Player2Draw (Graphics& gfx, Location& loc) const;

private:
	static constexpr int radius = 30;
	bool is_selected = false;
	Board& brd;
};

