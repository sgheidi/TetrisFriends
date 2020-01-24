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

/* all global variables and options declared here */

// color mapping directives
#define BLACK 0
#define GREEN 1
#define RED 2
#define ORANGE 3
#define PURPLE 4
#define YELLOW 5

extern const int ScreenX;
extern const int ScreenY;
extern const float unit;

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
