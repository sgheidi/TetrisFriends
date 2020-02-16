#include "../include/common.h"

void Tetronimo_7::RenderTetronimo() {
  glPushMatrix();

  Util.ColorBuffer(TETRONIMO_7_COLOR);
  Util.DrawSquare();
  glTranslatef(-1*unit, 0.0f, 0.0f);
  Util.DrawSquare();
  glTranslatef(0.0f, unit, 0.0f);
  Util.DrawSquare();
  glTranslatef(unit, 0.0f, 0.0f);
  Util.DrawSquare();

  glPopMatrix();
}

void Tetronimo_7::RenderOutline(int TopRow) {
  glPushMatrix();

  Util.OutlineSquare(TopRow);
  glTranslatef(-1*unit, 0.0f, 0.0f);
  Util.OutlineSquare(TopRow);
  glTranslatef(0.0f, unit, 0.0f);
  Util.OutlineSquare(TopRow);
  glTranslatef(unit, 0.0f, 0.0f);
  Util.OutlineSquare(TopRow);

  glPopMatrix();
}

bool Tetronimo_7::InWindowLeft() {
  return col >= 2;
}

bool Tetronimo_7::InWindowRight() {
  return col <= 8;
}

void Tetronimo_7::FillBlocks() {
  blocks[col][row-1] = 1;
  blocks[col][row] = 1;
  blocks[col+1][row-1] = 1;
  blocks[col+1][row] = 1;
}

void Tetronimo_7::FillColors() {
  colors[col][row-1] = TETRONIMO_7_COLOR;
  colors[col][row] = TETRONIMO_7_COLOR;
  colors[col+1][row-1] = TETRONIMO_7_COLOR;
  colors[col+1][row] = TETRONIMO_7_COLOR;
}

void Tetronimo_7::OutlineBlocks(int NewRow) {
  colors[col][NewRow-1] = GREY;
  colors[col][NewRow] = GREY;
  colors[col+1][NewRow-1] = GREY;
  colors[col+1][NewRow] = GREY;
}

/* Collision functions return true if a potential collision is detected */
// note that pivot coordinates are blocks[col][row]
bool Tetronimo_7::CheckCollisionRight() {
  if(blocks[col+2][row] == 1 || blocks[col+2][row+1] == 1) {
    return true;
  }
}

// note that pivot coordinates are blocks[col][row]
bool Tetronimo_7::CheckCollisionLeft() {
  if(blocks[col-1][row] == 1 || blocks[col-1][row+1] == 1) {
    return true;
  }
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_7::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

// if any condition for stacking is detected, returns true
bool Tetronimo_7::StackingCriteria() {
  if (row >= 20 || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
    return true;
  }
}
