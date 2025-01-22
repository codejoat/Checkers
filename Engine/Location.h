#pragma once

class Location
{
public:
	Location () = default;
	Location (int set_x, int set_y);
	void Add (const Location& val);
	int x;
	int y;
};

