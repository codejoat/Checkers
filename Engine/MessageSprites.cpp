#include "MessageSprites.h"

void MessageSprites::DrawPressEnter (Graphics& gfx) const {
	ch.Draw_P (Position (190, 280), gfx, 4, Colors::White);
	ch.Draw_R (Position (230, 280), gfx, 4, Colors::White);
	ch.Draw_E (Position (270, 280), gfx, 4, Colors::White);
	ch.Draw_S (Position (310, 280), gfx, 4, Colors::White);
	ch.Draw_S (Position (350, 280), gfx, 4, Colors::White);
	
	ch.Draw_Full_Space (Position (390, 280), gfx, 4, Colors::Black, false);
	
	ch.Draw_E (Position (430, 280), gfx, 4, Colors::White);
	ch.Draw_N (Position (470, 280), gfx, 4, Colors::White);
	ch.Draw_T (Position (510, 280), gfx, 4, Colors::White);
	ch.Draw_E (Position (540, 280), gfx, 4, Colors::White);
	ch.Draw_R (Position (580, 280), gfx, 4, Colors::White);
}

void MessageSprites::DrawPlayer1 (Graphics& gfx) const { 
	ch.Draw_P (Position (25, 15), gfx, 4, Color(5, 5, 5));
	ch.Draw_1 (Position (65, 15), gfx, 4, Color(5, 5, 5));
}

void MessageSprites::DrawPlayer2 (Graphics& gfx) const { 
	ch.Draw_P (Position (710, 15), gfx, 4, Color (165, 10, 10));
	ch.Draw_2 (Position (750, 15), gfx, 4, Color (165, 10, 10));
}

void MessageSprites::DrawWinner (Graphics& gfx, PlayerType which_player, Color c) const {
	if(which_player == PlayerType::p1) {
		ch.Draw_1 (Position (380, 220), gfx, 16, c);
	} else {
		ch.Draw_2 (Position (370, 220), gfx, 16, c);
	}
	
	
	
	ch.Draw_P (Position (140, 300), gfx, 4, Colors::Cyan);
	ch.Draw_L (Position (180, 300), gfx, 4, Colors::Cyan);
	ch.Draw_A (Position (220, 300), gfx, 4, Colors::Cyan);
	ch.Draw_Y (Position (260, 300), gfx, 4, Colors::Cyan);
	ch.Draw_E (Position (310, 300), gfx, 4, Colors::Cyan);
	ch.Draw_R (Position (350, 300), gfx, 4, Colors::Cyan);
	ch.Draw_W (Position (480, 300), gfx, 4, Colors::Cyan);
	ch.Draw_I (Position (530, 300), gfx, 4, Colors::Cyan);
	ch.Draw_N (Position (570, 300), gfx, 4, Colors::Cyan);
	ch.Draw_S (Position (610, 300), gfx, 4, Colors::Cyan);
}
