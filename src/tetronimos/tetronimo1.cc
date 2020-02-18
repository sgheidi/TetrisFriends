#include "../../include/common.h"

void Tetronimo_1::RenderTetronimo() {
  glPushMatrix();
  Util.ColorBuffer(TETRONIMO_1_COLOR);
  switch (Tetronimo1.RotationCounter) {
    case 0:
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      break;
    case 1:
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.DrawSquare();
      break;
    }
  glPopMatrix();
}

void Tetronimo_1::RenderOutline(int TopRow) {
  glPushMatrix();
  switch (Tetronimo1.RotationCounter) {
    case 0:
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 1:
      glTranslatef(unit, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    }
  glPopMatrix();
}

bool Tetronimo_1::InWindowLeft(){
  switch (Tetronimo1.RotationCounter) {
    case 0:
      return col >= 2;
      break;
    case 1:
      return col >= 4;
      break;
  }
}

bool Tetronimo_1::InWindowRight(){
  switch (Tetronimo1.RotationCounter) {
    case 0:
      return col <= 9;
      break;
    case 1:
      return col <= 8;
      break;
  }
}

void Tetronimo_1::FillBlocks(){
  switch (Tetronimo1.RotationCounter) {
    case 0:
      blocks[col][row-2] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row] = 1;
      blocks[col][row+1] = 1;
      break;
    case 1:
      blocks[col+1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col-1][row-1] = 1;
      blocks[col-2][row-1] = 1;
      break;
  }
}

void Tetronimo_1::FillColors(){
  switch (Tetronimo1.RotationCounter) {
    case 0:
      colors[col][row-2] = TETRONIMO_1_COLOR;
      colors[col][row-1] = TETRONIMO_1_COLOR;
      colors[col][row] = TETRONIMO_1_COLOR;
      colors[col][row+1] = TETRONIMO_1_COLOR;
        break;
    case 1:
      colors[col+1][row-1] = TETRONIMO_1_COLOR;
      colors[col][row-1] = TETRONIMO_1_COLOR;
      colors[col-1][row-1] = TETRONIMO_1_COLOR;
      colors[col-2][row-1] = TETRONIMO_1_COLOR;
      break;
  }
}

/* Collision functions return true if a potential collision is detected */
// note that pivot coordinates are blocks[col][row]
bool Tetronimo_1::CheckCollisionRight() {
  switch (Tetronimo1.RotationCounter) {
    case 0:
      if(blocks[col+1][row-1] == 1 || blocks[col+1][row] == 1
      || blocks[col+1][row+1] == 1
      || blocks[col+1][row+2] == 1) {
        return true;
      }
      break;
    case 1:
      if(blocks[col+2][row] == 1){
        return true;
      }
      break;
  }
  return false;
}

// note that pivot coordinates are blocks[col][row]
bool Tetronimo_1::CheckCollisionLeft() {
  switch (Tetronimo1.RotationCounter) {
    case 0:
      if(blocks[col-1][row-1] == 1 || blocks[col-1][row] == 1
      || blocks[col-1][row+1] == 1
      || blocks[col-1][row+2] == 1) {
        return true;
      }
      break;
    case 1:
      if(blocks[col-3][row] == 1) {
        return true;
      }
      break;
  }
  return false;
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_1::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

// if any condition for stacking is detected, returns true
bool Tetronimo_1::StackingCriteria(){
  switch(Tetronimo1.RotationCounter) {
    case 0:
      if (row >= 19 || blocks[col][row+2] == 1) {
        return true;
      }
      break;
    case 1:
      if (row >= 21 || blocks[col-2][row] == 1 || blocks[col-1][row] == 1
      || blocks[col][row] == 1 || blocks[col+1][row] == 1) {
        return true;
      }
      break;
  }
  return false;
}
