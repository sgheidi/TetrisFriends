#include "../include/common.h"

void Tetronimo_7::RenderTetronimo() {
  glPushMatrix();

  Util.DrawSquare(YELLOW);
  glTranslatef(-1*unit, 0.0f, 0.0f);
  Util.DrawSquare(PURPLE);
  glTranslatef(0.0f, unit, 0.0f);
  Util.DrawSquare(RED);
  glTranslatef(unit, 0.0f, 0.0f);
  Util.DrawSquare(ORANGE);

  glPopMatrix();
}

bool Tetronimo_7::InWindowLeft(){
  return col >= 2;
}

bool Tetronimo_7::InWindowRight(){
  return col <= 8;
}

void Tetronimo_7::FillBlocks(){
  blocks[col][row-1] = 1;
  blocks[col][row] = 1;
  blocks[col+1][row-1] = 1;
  blocks[col+1][row] = 1;
}

void Tetronimo_7::FillColors(){
  colors[col][row-1] = PURPLE;
  colors[col][row] = RED;
  colors[col+1][row-1] = YELLOW;
  colors[col+1][row] = ORANGE;
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
bool Tetronimo_7::StackingCriteria(){
  if (row >= 20 || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
    return true;
  }
}
