#pragma once

#include <utility>

struct Position {
	Position () = default;
	Position (int set_x, int set_y)
		:
		x (set_x),
		y (set_y)
	{
	}
	Position (const std::pair<int, int>& pos)
		:
		x (pos.first),
		y (pos.second)
	{
	}

	bool operator == (const Position& rhs) const {
		return this->x == rhs.x && this->y == rhs.y;
	}
	bool operator <= (const Position& rhs) const {
		return this->x <= rhs.x && this->y <= rhs.y;
	}
	bool operator >= (const Position& rhs) const {
		return this->x >= rhs.x && this->y >= rhs.y;
	}
	bool operator != (const Position& rhs) const {
		return this->x != rhs.x && this->y != rhs.y;
	}
	Position operator + (int value) const {
		return Position (this->x + value, this->y + value);
	}
	Position operator - (int value) const {
		return Position (this->x - value, this->y - value);
	}
	int x;
	int y;
};


