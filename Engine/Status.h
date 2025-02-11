#include <ostream>

#pragma once

enum class PlayerStatus {
	non,
	hover,
	select
};

enum class PieceType {
	man,
	king,
	destroyed
};

enum class PlayerType {
	p0,
	p1,
	p2
};

std::ostream& operator << (std::ostream& os, PlayerStatus status);
std::ostream& operator << (std::ostream& os, PieceType type);
std::ostream& operator << (std::ostream& os, PlayerType type);