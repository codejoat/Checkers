#include "Status.h"

std::ostream& operator << (std::ostream& os, PlayerStatus status) {
	switch(status) {
	case PlayerStatus::non: os << "non"; break;
	case PlayerStatus::hover: os << "hover"; break;
	case PlayerStatus::select: os << "select"; break;
	}
	return os;
}

std::ostream& operator << (std::ostream& os, PieceType type) {
	switch(type) {
	case PieceType::man: os << "man"; break;
	case PieceType::king: os << "king"; break;
	case PieceType::destroyed: os << "destroyed"; break;
	}
	return os;
}

std::ostream& operator << (std::ostream& os, PlayerType type) {
	switch(type) {
	case PlayerType::p0: os << "p0"; break;
	case PlayerType::p1: os << "p1"; break;
	case PlayerType::p2: os << "p2"; break;
	}
	return os;
}