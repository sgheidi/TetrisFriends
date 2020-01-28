#include "../include/board.h"
#include "../include/common.h"

// units are assigned based on Tetronimo piece
void Board::Init(){
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

void Board::ResetUnits(){
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
  glBegin(GL_LINES);
  // horizontal lines
  glVertex2f(0, 1);
  glVertex2f(ScreenX, 1);
  for (int i = 0; i < ScreenY + 20; i += unit) {
    glVertex2f(0, i);
    glVertex2f(ScreenX, i);
  }
  // vertical lines
  glVertex2f(0, 1);
  glVertex2f(1, ScreenY);
  for (int i = 0; i < ScreenX + 20; i += unit) {
    glVertex2f(i, 0);
    glVertex2f(i, ScreenY);
  }
  glEnd();
  glFlush();
}

// draws all blocks that have already landed
void Board::RenderDroppedBlocks() {
  for(int i=1;i<=10;i++){
    for(int j=1;j<=20;j++){
      if(blocks[i][j] == 1){
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

//
/* line clearing functions below */
//
void Board::ClearLine(int row) {
  for(int col=1;col<=10;col++){
    blocks[col][row] = 0;
    colors[col][row] = 0;
  }
}

bool Board::IsRowFull(int row) {
  for(int col=1;col<=10;col++){
    if(blocks[col][row] == 0) {
      return false;
    }
  }
  return true;
}

// y (row) is the row that the lines should be brought down to
// and NumLines is the number of rows they should come down
void Board::BringLinesDown(int y, int NumLines){
  for(int x=1;x<=10;x++){
    for(int vert=y;vert>=1;vert--){
      if (blocks[x][vert] == 1) {
        blocks[x][vert + NumLines] = 1;
        colors[x][vert + NumLines] = colors[x][vert];
        blocks[x][vert] = 0;
        colors[x][vert] = BLACK;
      }
    }
  }
}

// core function for clearing lines
void Board::LineClear() {
  int TopMostRow = 0;
  int LinesCleared = 0;
  for(int y=20;y>=1;y--){
    if(this->IsRowFull(y) == true) {
      this->ClearLine(y);
      LinesCleared ++;
      TopMostRow = y-1;
    }
  }
  if (LinesCleared >=1) {
    this->BringLinesDown(TopMostRow, LinesCleared);
  }
}
