#pragma once

#include "Location.h"
#include "Graphics.h"

class Players
{
public:
	void Player1Move (const Location& delta_loc);
	void Player1Draw (Graphics& gfx, Location& loc) const;

public:
	void Player2Move (Location& delta_loc);
	void Player2Draw (Graphics& gfx, Location& loc) const;

private:
	Location player1_loc;
	Location player2_loc;
	static constexpr int radius = 30;
	int x;
	int y;
};

