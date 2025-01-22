#include "Location.h"

Location::Location (int set_x, int set_y)
	:
	x(set_x),
	y(set_y)
{
}

void Location::Add (const Location& val)
{
	x += val.x;
	y += val.y;
}
