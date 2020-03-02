#ifndef COMMON_H
#define COMMON_H

#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <assert.h>

#include "utility.h"
#include "board.h"
#include "hard_drop.h"
#include "lineclear.h"
#include "queue.h"
#include "tetronimos/tetronimo1.h"
#include "tetronimos/tetronimo2.h"
#include "tetronimos/tetronimo3.h"
#include "tetronimos/tetronimo4.h"
#include "tetronimos/tetronimo5.h"
#include "tetronimos/tetronimo6.h"
#include "tetronimos/tetronimo7.h"

extern GLFWwindow* window;
void inputK(GLFWwindow* window, int key, int scancode, int action, int mods);

/* all global variables and options declared here */

#define DEFAULT_GAME_SPEED 30

// color mapping macros
// for definitions see Utility::ColorBuffer
#define BLACK 0
#define GREEN 1
#define RED 2
#define ORANGE 3
#define PURPLE 4
#define YELLOW 5
#define BLUE 6
#define CYAN 7
#define GREY 10

// define macros for each tetronimo's color
#define TETRONIMO_1_COLOR GREEN
#define TETRONIMO_2_COLOR CYAN
#define TETRONIMO_3_COLOR ORANGE
#define TETRONIMO_4_COLOR PURPLE
#define TETRONIMO_5_COLOR YELLOW
#define TETRONIMO_6_COLOR BLUE
#define TETRONIMO_7_COLOR RED

extern const int ScreenX;
extern const int ScreenY;
extern const float unit;

// arrays keeping track of filled/nonfilled
// and colors of each block
extern int blocks[11][21];
extern int colors[11][21];

extern int holdcolors[5][5];

// struct holding the colors for the
// 'next' tetronimos (top-down)
struct _next_ {
  int colors1[5][5];
  int colors2[5][5];
  int colors3[5][5];
  int colors4[5][5];
};
extern struct _next_ Next;

extern bool Paused;
extern bool GameOver;
extern int Rand[5];

extern bool Testing;
extern int TestRand;

struct _timer_ {
  int NumIterations;
  int GameSpeed;
};
extern struct _timer_ Timer;

// pivot coordinates (pixels)
extern float x;
extern float y;

// pivot coordinates (block)
extern int row;
extern int col;

#endif // COMMON_H
