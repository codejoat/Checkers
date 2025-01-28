#pragma once

#include <utility>

struct Location {
	Location () = default;
	Location (int set_x, int set_y)
		:
		x (set_x),
		y (set_y)
	{
	}
	Location (const std::pair<int, int>& pos)
		:
		x (pos.first),
		y (pos.second)
	{
	}

	bool operator == (const Location& rhs) const {
		return this->x == rhs.x && this->y == rhs.y;
	}
	bool operator <= (const Location& rhs) const {
		return this->x <= rhs.x && this->y <= rhs.y;
	}
	bool operator >= (const Location& rhs) const {
		return this->x >= rhs.x && this->y >= rhs.y;
	}
	Location operator + (int value) const {
		return Location (this->x + value, this->y + value);
	}
	Location operator - (int value) const {
		return Location (this->x - value, this->y - value);
	}
	int x;
	int y;
};

