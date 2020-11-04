#include "../common.h"

void Utility::test() {
  GameBoard.Test();
}

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
      glColor3f(0.0f, 0.8f, 0.0f);
      break;
    case RED:
      glColor3f(0.8f, 0.0f, 0.0f);
      break;
    case ORANGE:
      glColor3f(0.8f, 0.3f, 0.0f);
      break;
    case PURPLE:
      glColor3f(0.8f, 0.3f, 0.8f);
      break;
    case YELLOW:
      glColor3f(0.8f, 0.8f, 0.0f);
      break;
    case BLUE:
      glColor3f(0.15f, 0.5f, 1.0f);
      break;
    case CYAN:
      glColor3f(0.2f, 0.9f, 0.85f);
      break;
    case GREY:
      glColor3f(0.75f, 0.75f, 0.75f);
      break;
    default:
      glColor3f(0.0f, 0.0f, 0.0f);
  }
}

// core function that draws individual (moving) blocks
void Utility::DrawSquare() {
  glBegin(GL_POLYGON);

  glVertex2f(x, y);
  glVertex2f(x, y+unit);
  glVertex2f(x+unit, y+unit);
  glVertex2f(x+unit, y);

  glEnd();
}

// Core function for drawing the grey blocks
// for hard-dropping
void Utility::OutlineSquare(int _row_) {
  _row_--;
  this->ColorBuffer(GREY);
  glBegin(GL_POLYGON);

  glVertex2f(x, (unit*_row_)-unit);
  glVertex2f(x, unit*_row_);
  glVertex2f(x+unit, unit*_row_);
  glVertex2f(x+unit, (unit*_row_)-unit);

  glEnd();
}

// empty the board by zero-ing
// both 'blocks' and 'colors' arrays
void Utility::ZeroArrays() {
  for (int i=1;i<=10;i++) {
    for (int j=1;j<=20;j++) {
      blocks[i][j] = 0;
      colors[i][j] = BLACK;
    }
  }
  for (int i=1;i<=4;i++) {
    for (int j=1;j<=4;j++) {
      holdcolors[i][j] = BLACK;
      Next.colors1[i][j] = BLACK;
      Next.colors2[i][j] = BLACK;
      Next.colors3[i][j] = BLACK;
      Next.colors4[i][j] = BLACK;
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
  for(int x=1;x<=10;x++) {
    for(int y=1;y<=20;y++) {
      if(blocks[x][y] == 1) {
        std::cout << "blocks[" << x << "][" << y << "] is full"<< std::endl;
      }
    }
  }
}

void Utility::PrintCurrentPosition() {
  std::cout << "Row " << row << "  Col " << col << std::endl;
}
