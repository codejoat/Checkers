#include "Graphics.h"
#include "Colors.h"
#include "Position.h"
#include "Status.h"
#include "AlphaNumericSprites.h"

#pragma once


class MessageSprites {
public:
	void DrawPressEnter (Graphics& gfx) const;
	void DrawPlayer1 (Graphics& gfx) const;
	void DrawPlayer2 (Graphics& gfx) const;
	void DrawWinner (Graphics& gfx, PlayerType which_player, Color c) const;

private:
	AlphaNumericSprites ch;
};

