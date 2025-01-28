#pragma once

#include "Location.h"
#include "Graphics.h"
#include "Board.h"
#include "Mouse.h"

class Players {
	
private:
	Location location;

public:
	Players () = default;
	void Draw (Graphics& gfx, Location& location, const int which_player, const int status) const;
	void Update (const Location& new_location, const int new_status);
	int GetStatus () const;
	Location GetLocation (const Board& board, const int which_man) const;


private:
	static constexpr int man = 0;
	static constexpr int king = 1;
	static constexpr int hover = 2;
	static constexpr int select = 3;
	static constexpr int radius = 30;
	
	bool is_selected = false;
	bool destroyed = false;

	int status = man;
};

/*
	for(int i = 0; i < 12; i++) {
		const int player1X = brd.GetTileLocation (player1[i]).x;
		const int player1Y = brd.GetTileLocation (player1[i]).y;
		const int player2X = brd.GetTileLocation (player2[i]).x;
		const int player2Y = brd.GetTileLocation (player2[i]).y;

		players.Player2Draw (gfx, brd.GetTileLocation (player2[i]));
		players.Player1Draw (gfx, brd.GetTileLocation (player1[i]));

		SetState (player1X, player1Y);
		SetState (player2X, player2Y);
	}
}

void Game::SetState (const int& playerX, const int& playerY)
{
	const int mouseX = wnd.mouse.GetPosX ();
	const int mouseY = wnd.mouse.GetPosY ();

	if(mouseX <= playerX + 20 && mouseX >= playerX - 20 &&
		mouseY <= playerY + 20 && mouseY >= playerY - 20) {
		if(wnd.mouse.LeftIsPressed ()) {
			DrawStatus (king, playerX, playerY);
		} else if(wnd.mouse.RightIsPressed ()) {
			DrawStatus (select, playerX, playerY);
		} else {
			DrawStatus (hover, playerX, playerY);
		}
	}
}*/