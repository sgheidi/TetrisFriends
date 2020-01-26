#include "../include/utility.h"
#include "../include/common.h"

void Tetronimo_4::RenderTetronimo() {
  glPushMatrix();
  switch (Tetronimo4.RotationCounter) {
    case 0:
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare(GREEN);
      glTranslatef(-1*unit, 0.0f , 0.0f);
      Util.DrawSquare(ORANGE);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare(PURPLE);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare(YELLOW);
      break;
    case 1:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.DrawSquare(GREEN);
      glTranslatef(0.0f, -1*unit , 0.0f);
      Util.DrawSquare(ORANGE);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare(PURPLE);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare(YELLOW);
      break;
  }
  glPopMatrix();
}

bool Tetronimo_4::InWindowLeft(){
  switch (Tetronimo4.RotationCounter) {
    case 0:
      return col >= 3;
      break;
    case 1:
      return col >= 3;
      break;
    }
}

bool Tetronimo_4::InWindowRight() {
  switch (Tetronimo4.RotationCounter) {
    case 0:
      return col <= 8;
      break;
    case 1:
      return col <= 9;
      break;
    }
}

void Tetronimo_4::FillBlocks(){
  switch (Tetronimo4.RotationCounter) {
    case 0:
      blocks[col+1][row] = 1;
      blocks[col][row] = 1;
      blocks[col][row-1] = 1;
      blocks[col-1][row-1] = 1;
      break;
    case 1:
      blocks[col-1][row] = 1;
      blocks[col-1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row-2] = 1;
      break;
  }
}

void Tetronimo_4::FillColors(){
  switch (Tetronimo4.RotationCounter) {
    case 0:
      colors[col-1][row-1] = YELLOW;
      colors[col][row-1] = PURPLE;
      colors[col][row] = ORANGE;
      colors[col+1][row] = GREEN;
      break;
    case 1:
      colors[col-1][row] = GREEN;
      colors[col-1][row-1] = ORANGE;
      colors[col][row-1] = PURPLE;
      colors[col][row-2] = YELLOW;
      break;
  }
}

/* Collision functions return true if a potential collision is detected */
// note that pivot coordinates are blocks[col][row]
bool Tetronimo_4::CheckCollisionRight() {
  switch (Tetronimo4.RotationCounter){
    case 0:
      if(blocks[col+1][row] == 1 || blocks[col+2][row+1] == 1) {
        return true;
      }
      break;
    case 1:
      if(blocks[col][row+1] == 1 || blocks[col+1][row] == 1
      || blocks[col+1][row-1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// note that pivot coordinates are blocks[col][row]
bool Tetronimo_4::CheckCollisionLeft() {
  switch (Tetronimo4.RotationCounter) {
    case 0:
      if(blocks[col-2][row] == 1 || blocks[col-1][row+1] == 1){
        return true;
      }
      break;
    case 1:
      if(blocks[col-1][row-1] == 1 || blocks[col-2][row] == 1
      || blocks[col-2][row+1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_4::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

// if any condition for stacking is detected, returns true
bool Tetronimo_4::StackingCriteria(){
  switch(Tetronimo4.RotationCounter){
    case 0:
        if (row >= 20 || blocks[col-1][row] == 1 || blocks[col][row+1] == 1
        || blocks[col+1][row+1] == 1) {
          return true;
        }
      break;
    case 1:
      if (row >= 20 || blocks[col-1][row+1] == 1 || blocks[col][row] == 1) {
        return true;
      }
      break;
    }
      return false;
}
