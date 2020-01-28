#include "../include/utility.h"
#include "../include/common.h"

void Utility::GoDown() {
  y += unit;
  row ++;
}

void Utility::AccelerateDown() {
  y += unit;
  row ++;
}

void Utility::GoRight() {
  x += unit;
  col ++;
}

void Utility::GoLeft() {
  x -= unit;
  col --;
}

// colors the buffer with specified color
void Utility::ColorBuffer(int color) {
  switch (color) {
    case BLACK:
      glColor3f(0.0f, 0.0f, 0.0f);
      break;
    case GREEN:
      glColor3f(0.0f, 1.0f, 0.0f);
      break;
    case RED:
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case ORANGE:
      glColor3f(1.0f, 0.5f, 0.0f);
      break;
    case PURPLE:
      glColor3f(1.0f, 0.5f, 1.5f);
      break;
    case YELLOW:
      glColor3f(1.0f, 1.0f, 0.0f);
      break;
    default:
      glColor3f(0.0f, 0.0f, 0.0f);
  }
}

// core function that draws individual blocks
// with specified color
void Utility::DrawSquare(int color) {
  this->ColorBuffer(color);
  glBegin(GL_POLYGON);

  glVertex2f(x, y);
  glVertex2f(x, y+unit);
  glVertex2f(x+unit, y+unit);
  glVertex2f(x+unit, y);

  glEnd();
}

// empty the board by zero-ing
// both 'blocks' and 'colors' arrays
void Utility::ZeroArrays() {
  for(int i=1;i<=10;i++){
    for(int j=1;j<=20;j++){
      blocks[i][j] = 0;
      colors[i][j] = BLACK;
    }
  }
}

// this function returns the top-most row
// of a specified column
// (used for 'hard' dropping tetronimos)
int Utility::FindTopMostRow(int x) {
  for (int i=20;i>=1;i--) {
    if (blocks[x][i] == 0) {
      return i;
    }
  }
  return 20;
}

/* Helper functions to track pivot position */
void Utility::PrintFilledBlocks() {
  for(int x=1;x<=10;x++){
    for(int y=1;y<=20;y++){
      if(blocks[x][y] == 1){
          cout << "blocks[" << x << "][" << y << "] is full"<<endl;
      }
    }
  }
}

void Utility::PrintCurrentPosition() {
  cout << "Row " << row << "  Col " << col << endl;
}
