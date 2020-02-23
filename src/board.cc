#include "../include/common.h"

// initial coordinates are assigned based on Tetronimo piece
void Board::Init() {
  switch (Rand) {
    case 1:
      row = 2;
      col = 6;
      break;
    case 2:
      row = 2;
      col = 6;
      break;
    case 3:
      row = 1;
      col = 6;
      break;
    case 4:
      row = 1;
      col = 6;
      break;
    case 5:
      row = 1;
      col = 6;
      break;
    case 6:
      row = 1;
      col = 6;
      break;
    case 7:
      row = 1;
      col = 5;
      break;
  }
}

void Board::ResetUnits() {
  switch (Rand) {
    case 1:
      x = unit*5;
      y= 0;
      row = 2;
      col = 6;
      break;
    case 2:
      x = unit*5;
      y= 0;
      row = 2;
      col = 6;
      break;
    case 3:
      x = unit*5;
      y= 0;
      row = 1;
      col = 6;
      break;
    case 4:
      x = unit*5;
      y= 0;
      row = 1;
      col = 6;
      break;
    case 5:
      x = unit*5;
      y= 0;
      row = 1;
      col = 6;
      break;
    case 6:
      x = unit*5;
      y= 0;
      row = 1;
      col = 6;
      break;
    case 7:
      x = unit*5;
      y= 0;
      row = 1;
      col = 5;
      break;
  }
}

// draw n horizontal lines with beginning & end coordinates
void Board::Horizontal(int startX, int endX, int startY, int endY) {
  glBegin(GL_LINES);
  for (auto i = startY; i <= endY + unit; i += unit) {
    glVertex2f(startX, i);
    glVertex2f(endX, i);
  }
  glEnd();
}

void Board::Vertical(int startX, int endX, int startY, int endY) {
  glBegin(GL_LINES);
  for (auto i = startX; i <= endX; i += unit) {
    glVertex2f(i, startY);
    glVertex2f(i, endY);
  }
  glEnd();
}

void Board::DrawGrid() {
  float ratio;
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  ratio = width / (float)height;
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, height, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor3f(1.0f, 1.0f, 1.0f);
  // draw a small 3x3 box on left side
  // to show held piece in queue
  this->Horizontal(unit/2, 4.5*unit, 3*unit, 6*unit);
  this->Vertical(unit/2, 4.5*unit, 3*unit, 7*unit);
  // draw main board
  glTranslatef(5*unit, 0.0f, 0.0f);
  this->Horizontal(0, ScreenX, 1, ScreenY);
  this->Vertical(0 , ScreenX, 0, ScreenY);
  // draw 4 3x3 boxes on right side
  // to show the 4 next pieces in queue
  glPushMatrix();
  glTranslatef(ScreenX, 0.0f, 0.0f);
  this->Horizontal(unit/2, 4.5*unit, unit, 4*unit);
  this->Vertical(unit/2, 4.5*unit, unit, 5*unit);
  glPopMatrix();
  glFlush();
}

// draws all blocks that have already landed
// for board
void Board::RenderBlocks_Board() {
  for (int i=1;i<=10;i++) {
    for (int j=1;j<=20;j++) {
      if (blocks[i][j] == 1) {
        Util.ColorBuffer(colors[i][j]);
        glPushMatrix();
        glBegin(GL_POLYGON);

        glVertex2f(i*unit, (j*unit)-unit);
        glVertex2f(i*unit, j*unit);
        glVertex2f((i*unit)-unit, j*unit);
        glVertex2f((i*unit)-unit, (j*unit)-unit);

        glEnd();
        glPopMatrix();
      }
    }
  }
}

// draws all blocks that have already landed
// for held piece
void Board::RenderBlocks_Hold() {
  for (int i=1;i<=4;i++) {
    for (int j=1;j<=4;j++) {
      if (holdcolors[i][j] != BLACK) {
        Util.ColorBuffer(holdcolors[i][j]);
        glPushMatrix();
        glTranslatef(-4.5*unit, 3*unit, 0.0f);
        glBegin(GL_POLYGON);

        glVertex2f(i*unit, (j*unit)-unit);
        glVertex2f(i*unit, j*unit);
        glVertex2f((i*unit)-unit, j*unit);
        glVertex2f((i*unit)-unit, (j*unit)-unit);

        glEnd();
        glPopMatrix();
      }
    }
  }
}

void Board::SwitchTetronimo() {
  // clear the old colors to replace with new
  // everytime 'shift' is pressed
  for (int i=1;i<=4;i++) {
    for (int j=1;j<=4;j++) {
      holdcolors[i][j] = BLACK;
    }
  }
  switch (Rand) {
    case 1:
      for (int i=1;i<=4;i++) {
        holdcolors[i][3] = TETRONIMO_1_COLOR;
      }
      Tetronimo1.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 1;
      break;
    case 2:
      for (int i=1;i<=3;i++) {
        holdcolors[i][3] = TETRONIMO_2_COLOR;
      }
      holdcolors[2][2] = TETRONIMO_2_COLOR;
      Tetronimo2.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 2;
      break;
    case 3:
      holdcolors[2][3] = TETRONIMO_3_COLOR;
      holdcolors[3][3] = TETRONIMO_3_COLOR;
      holdcolors[3][2] = TETRONIMO_3_COLOR;
      holdcolors[4][2] = TETRONIMO_3_COLOR;
      Tetronimo3.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 3;
      break;
    case 4:
      holdcolors[3][3] = TETRONIMO_4_COLOR;
      holdcolors[2][3] = TETRONIMO_4_COLOR;
      holdcolors[2][2] = TETRONIMO_4_COLOR;
      holdcolors[1][2] = TETRONIMO_4_COLOR;
      Tetronimo4.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 4;
      break;
    case 5:
      holdcolors[2][3] = TETRONIMO_5_COLOR;
      holdcolors[2][2] = TETRONIMO_5_COLOR;
      holdcolors[3][2] = TETRONIMO_5_COLOR;
      holdcolors[4][2] = TETRONIMO_5_COLOR;
      Tetronimo5.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 5;
      break;
    case 6:
      holdcolors[3][3] = TETRONIMO_6_COLOR;
      holdcolors[2][3] = TETRONIMO_6_COLOR;
      holdcolors[2][2] = TETRONIMO_6_COLOR;
      holdcolors[2][1] = TETRONIMO_6_COLOR;
      Tetronimo6.RotationCounter = 0;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 6;
      break;
    case 7:
      holdcolors[2][2] = TETRONIMO_7_COLOR;
      holdcolors[3][2] = TETRONIMO_7_COLOR;
      holdcolors[3][3] = TETRONIMO_7_COLOR;
      holdcolors[2][3] = TETRONIMO_7_COLOR;
      if (InQueue!=0)
        Rand = InQueue;
      else if (InQueue == 0) {
        Rand = (rand()%7)+1;
      }
      if (Testing) Rand = TestRand;
      GameBoard.ResetUnits();
      InQueue = 7;
      break;
  }
}
