#ifndef COMMON_H
#define COMMON_H

#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>

#include "utility.h"
#include "board.h"
#include "tetronimo1.h"
#include "tetronimo2.h"

using namespace std;

extern GLFWwindow* window;
void inputK(GLFWwindow* window, int key, int scancode, int action, int mods);

/* all global variables and options defined here */

extern int ScreenX;
extern int ScreenY;
extern float unit;

extern int blocks[11][21];
extern int colors[11][21];

extern int NumIterations;
extern bool Paused;
extern int Rand;

extern int GameSpeed;
/* pivot is always purple block. */
// pivot coordinates of top-most block (pixels)
extern float x;
extern float y;

// pivot coordinates (block)
extern int row;
extern int col;

#endif
