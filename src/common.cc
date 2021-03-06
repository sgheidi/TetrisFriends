#include "common.h"

// initialize global classes
Utility Util;
Tetronimo_1 Tetronimo1;
Tetronimo_2 Tetronimo2;
Tetronimo_3 Tetronimo3;
Tetronimo_4 Tetronimo4;
Tetronimo_5 Tetronimo5;
Tetronimo_6 Tetronimo6;
Tetronimo_7 Tetronimo7;
Board GameBoard;
Hard_Drop HardDropper;
_LineClear_ LineClearer;
_queue_ Queue;

GLFWwindow* window;

// main grid width & height (pixels)
const int ScreenX = 400;
const int ScreenY = 800;

// Area of 1 block (pixels)
const float unit = ScreenX/10;

int blocks[11][21] = {0};
int colors[11][21] = {0};

int holdcolors[5][5] = {0};

struct _next_ Next = {0, 0, 0, 0};

float x = unit*5;
float y = 0;

bool Paused = false;
bool GameOver = false;
int Rand[5] = {0};
bool shift_allowed = true;

bool Testing = false;
int TestRand = 0;

struct _timer_ Timer = {
  0,
  DEFAULT_GAME_SPEED
};

int row = 0;
int col = 0;
