
#include <ncurses.h>
#include "ColorPairs.h"

/*

enum PairNames {
	WHITE_ON_BLACK = 1,
	RED_ON_BLACK = 2,
	YELLOW_ON_BLACK = 3,
	GREEN_ON_BLACK = 4,
	BLUE_ON_BLACK = 5,
	CYAN_ON_BLACK = 6,
	MAGENTA_ON_BLACK = 7
};

*/

void ColorPairs::InitializePairs() {
	start_color();
	init_pair(WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(YELLOW_ON_BLACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUE_ON_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(CYAN_ON_BLACK, COLOR_CYAN, COLOR_BLACK);
	init_pair(MAGENTA_ON_BLACK, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(BLACK_ON_YELLOW, COLOR_BLACK, COLOR_YELLOW);
}
