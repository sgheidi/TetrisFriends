#include "../common.h"

void Tetronimo_5::RenderTetronimo() {
  glPushMatrix();
  Util.ColorBuffer(TETRONIMO_5_COLOR);
  switch(Tetronimo5.RotationCounter) {
    case 0:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      break;
    case 1:
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      break;
    case 2:
      glTranslatef(unit, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      break;
    case 3:
      glTranslatef(-1*unit, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      break;
  }
  glPopMatrix();
}

void Tetronimo_5::RenderOutline(int TopRow) {
  glPushMatrix();
  switch(Tetronimo5.RotationCounter) {
    case 0:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 1:
      glTranslatef(unit, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 2:
      glTranslatef(unit, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 3:
      glTranslatef(-1*unit, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
  }
  glPopMatrix();
}

bool Tetronimo_5::InWindowLeft(){
  switch (Tetronimo5.RotationCounter) {
    case 0:
      return col >= 3;
      break;
    case 1:
      return col >= 2;
      break;
    case 2:
      return col >= 3;
      break;
    case 3:
      return col >= 3;
      break;
    }
}

bool Tetronimo_5::InWindowRight() {
  switch (Tetronimo5.RotationCounter) {
    case 0:
      return col <= 8;
      break;
    case 1:
      return col <= 8;
      break;
    case 2:
      return col <= 8;
      break;
    case 3:
      return col <= 9;
      break;
    }
}

void Tetronimo_5::FillBlocks(){
  switch (Tetronimo5.RotationCounter) {
    case 0:
      blocks[col-1][row] = 1;
      blocks[col-1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col+1][row-1] = 1;
      break;
    case 1:
      blocks[col+1][row] = 1;
      blocks[col][row] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row-2] = 1;
      break;
    case 2:
      blocks[col-1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col+1][row-1] = 1;
      blocks[col+1][row-2] = 1;
      break;
    case 3:
      blocks[col-1][row-2] = 1;
      blocks[col][row-2] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row] = 1;
      break;
  }
}

void Tetronimo_5::FillColors(){
  switch (Tetronimo5.RotationCounter) {
    case 0:
      colors[col-1][row] = TETRONIMO_5_COLOR;
      colors[col-1][row-1] = TETRONIMO_5_COLOR;
      colors[col][row-1] = TETRONIMO_5_COLOR;
      colors[col+1][row-1] = TETRONIMO_5_COLOR;
      break;
    case 1:
      colors[col+1][row] = TETRONIMO_5_COLOR;
      colors[col][row] = TETRONIMO_5_COLOR;
      colors[col][row-1] = TETRONIMO_5_COLOR;
      colors[col][row-2] = TETRONIMO_5_COLOR;
      break;
    case 2:
      colors[col+1][row-2] = TETRONIMO_5_COLOR;
      colors[col+1][row-1] = TETRONIMO_5_COLOR;
      colors[col][row-1] = TETRONIMO_5_COLOR;
      colors[col-1][row-1] = TETRONIMO_5_COLOR;
      break;
    case 3:
      colors[col-1][row-2] = TETRONIMO_5_COLOR;
      colors[col][row-2] = TETRONIMO_5_COLOR;
      colors[col][row-1] = TETRONIMO_5_COLOR;
      colors[col][row] = TETRONIMO_5_COLOR;
      break;
  }
}

/* Collision functions return true if a potential collision is detected */
// note that pivot coordinates are blocks[col][row]
bool Tetronimo_5::CheckCollisionRight() {
  switch (Tetronimo5.RotationCounter){
    case 0:
      if(blocks[col+2][row] == 1 || blocks[col][row+1] == 1) {
        return true;
      }
      break;
    case 1:
      if(blocks[col+1][row-1] == 1 || blocks[col+1][row] == 1
      || blocks[col+2][row+1] == 1){
        return true;
      }
      break;
    case 2:
      if(blocks[col+2][row] == 1 || blocks[col+2][row-1] == 1){
        return true;
      }
      break;
    case 3:
      if(blocks[col+1][row-1] == 1 || blocks[col+1][row] == 1
      || blocks[col+1][row+1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// note that pivot coordinates are blocks[col][row]
bool Tetronimo_5::CheckCollisionLeft() {
  switch (Tetronimo5.RotationCounter) {
    case 0:
      if(blocks[col-2][row] == 1 || blocks[col-2][row+1] == 1){
        return true;
      }
      break;
    case 1:
      if(blocks[col-1][row-1] == 1 || blocks[col-1][row] == 1
      || blocks[col-1][row+1] == 1){
        return true;
      }
      break;
    case 2:
      if(blocks[col-2][row] == 1 || blocks[col][row-1] == 1){
        return true;
      }
      break;
    case 3:
      if(blocks[col-2][row-1] == 1 || blocks[col-1][row] == 1
      || blocks[col-1][row+1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_5::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

// if any condition for stacking is detected, returns true
bool Tetronimo_5::StackingCriteria(){
  switch (Tetronimo5.RotationCounter) {
    case 0:
      if (row >= 20 || blocks[col-1][row+1] == 1 || blocks[col][row] == 1
      || blocks[col+1][row] == 1) {
        return true;
      }
      break;
    case 1:
      if (row >= 20 || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
        return true;
      }
      break;
    case 2:
      if (row >= 21 || blocks[col-1][row] == 1 || blocks[col][row] == 1
      || blocks[col+1][row] == 1) {
        return true;
      }
      break;
    case 3:
      if (row >= 20 || blocks[col-1][row-1] == 1 || blocks[col][row+1] == 1) {
        return true;
      }
      break;
    }
      return false;
}
