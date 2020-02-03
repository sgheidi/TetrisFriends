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

// returns the top-most row of a single column
// i.e the last occurance of a non-filled block
// that has a filled block before it
int Utility::FindTopRow_Single(int x) {
  int last = 20;
  for (int i=20;i>=row;i--) {
    if (blocks[x][i] == 0 && blocks[x][i+1] == 1) {
      last = i;
    }
  }
  return last;
}

// returns top-most row between columns StarCol and EndCol
int Utility::FindTopRow_Between(int StartCol, int EndCol) {
  assert(StartCol <= EndCol);
  int min = FindTopRow_Single(StartCol);
  for (int i=StartCol;i<=EndCol;i++) {
    if (FindTopRow_Single(i) < min) {
      min = FindTopRow_Single(i);
    }
  }
  return min;
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
