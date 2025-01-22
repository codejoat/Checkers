#pragma once

#include "Location.h"
#include "Graphics.h"

class Players
{
public:
	void Player1Draw (Graphics& gfx, Location& loc);
	void Player1SetLocation (const int set_location);
	int Player1GetLocation () const;

public:
	void Player2Draw (Graphics& gfx, Location& loc);
	void Player2SetLocation (const int set_location);
	int PLayer2GetLocation () const;

public:
	void Select ();

private:
	static constexpr int radius = 30;
	bool is_selected = false;
	int location;
};

