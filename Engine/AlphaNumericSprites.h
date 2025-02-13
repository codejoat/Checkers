#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Position.h"

class AlphaNumericSprites {
public:
	static void Draw_A (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_B (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_C (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_D (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_E (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_F (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_G (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_H (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_I (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_J (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_K (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_L (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_M (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_N (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_O (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_P (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_Q (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_R (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_S (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_T (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_U (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_V (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_W (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_X (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_Y (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_Z (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_0 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_1 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_2 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_3 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_4 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_5 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_6 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_7 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_8 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_9 (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_Colon (const Position& top_left, Graphics& gfx, int size_mod, Color c);
	static void Draw_Short_Space (const Position& top_left, Graphics& gfx, int size_mod, Color c, bool block);
	static void Draw_Full_Space (const Position& top_left, Graphics& gfx, int size_mod, Color c, bool block);

private:
	static constexpr int pixel_size = 2;
	static int font_size;
};

