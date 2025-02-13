#pragma once

#include <utility>

struct Position {
	Position ();
	Position (int set_x, int set_y);
	Position (const std::pair<int, int> position);

	bool operator == (const Position& rhs) const;
	bool operator <= (const Position& rhs) const;
	bool operator >= (const Position& rhs) const;
	bool operator != (const Position& rhs) const;
	Position operator + (int value) const;
	Position operator - (int value) const;

	int x = -1;
	int y = -1;
};


