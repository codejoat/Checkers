#include "AlphaNumericSprites.h"


int AlphaNumericSprites::font_size = 0;

void AlphaNumericSprites::Draw_A (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_B (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_C (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_D (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_E (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_F (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_G (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_H (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_I (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_J (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_K (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_L (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_M (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 4; x < top_left_x + font_size * 5; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_N (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_O (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_P (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_Q (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_R (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_S (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_T (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_U (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_V (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);


	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 4; x < top_left_x + font_size * 5; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_W (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 4; x < top_left_x + font_size * 5; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_X (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_Y (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 4; x < top_left_x + font_size * 5; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_Z (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_0 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	// Special 0 case to differentiate from O
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_1 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_2 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_3 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_4 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_5 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_6 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_7 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_8 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_9 (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 1; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 2; y < top_left_y + font_size * 3; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 4; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 2; x < top_left_x + font_size * 3; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 3; x < top_left_x + font_size * 4; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_Colon (const Position& top_left, Graphics& gfx, int size_mod, Color c) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 1; y < top_left_y + font_size * 2; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
	for(int y = top_left_y + font_size * 3; y < top_left_y + font_size * 4; ++y) {
		for(int x = top_left_x + font_size * 1; x < top_left_x + font_size * 2; ++x) {
			gfx.PutPixel (x, y, c);
		}
	}
}

void AlphaNumericSprites::Draw_Short_Space (const Position& top_left, Graphics& gfx, int size_mod, Color c, bool block) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 1; ++x) {
			if(block) {
				gfx.PutPixel (x, y, c);
			}
		}
	}
}

void AlphaNumericSprites::Draw_Full_Space (const Position& top_left, Graphics& gfx, int size_mod, Color c, bool block) {
	font_size = pixel_size * size_mod;
	const int top_left_x = int (top_left.x);
	const int top_left_y = int (top_left.y);

	for(int y = top_left_y + font_size * 0; y < top_left_y + font_size * 5; ++y) {
		for(int x = top_left_x + font_size * 0; x < top_left_x + font_size * 4; ++x) {
			if(block) {
				gfx.PutPixel (x, y, c);
			}
		}
	}
}
