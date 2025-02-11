#include "Position.h"

Position::Position () = default;
Position::Position (int set_x, int set_y)
	:
	x (set_x),
	y (set_y) { }
Position::Position (const std::pair<int, int> position)
	:
	x (position.first),
	y (position.second) { }

bool Position::operator == (const Position& rhs) const {
	return this->x == rhs.x && this->y == rhs.y;
}
bool Position::operator <= (const Position& rhs) const {
	return this->x <= rhs.x && this->y <= rhs.y;
}
bool Position::operator >= (const Position& rhs) const {
	return this->x >= rhs.x && this->y >= rhs.y;
}
bool Position::operator != (const Position& rhs) const {
	return this->x != rhs.x && this->y != rhs.y;
}
Position Position::operator + (int value) const {
	return Position (this->x + value, this->y + value);
}
Position Position::operator - (int value) const {
	return Position (this->x - value, this->y - value);
}