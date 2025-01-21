#pragma once

#include "Location.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{
public:
	Board (Graphics& set_gfx);
	void DrawCell (const Location& loc, Color c) const;
	void DrawBoard () const;
	int GetGridWidth () const;
	int GetGridHeight () const;

private:
	static constexpr int width = 8;
	static constexpr int height = 8;
	static constexpr int cell_dimension = 70;
	Graphics& gfx;
};

