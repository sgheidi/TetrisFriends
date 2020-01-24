#include "../include/common.h"

GLFWwindow* window;


// screen width & height (pixels)
const int ScreenX = 250;
const int ScreenY = 500;

// Area of 1 block (pixels)
const float unit = ScreenX/10;

int blocks[11][21] = {0};
int colors[11][21] = {0};

float x = unit*5;
float y = 0;

int NumIterations = 0;
bool Paused = false;
int Rand = 0;

// Decrease this to increase game speed
// Default should be 50
int GameSpeed = 50;

int row = 0;
int col = 0;
