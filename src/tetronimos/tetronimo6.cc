#include "../common.h"

void Tetronimo_6::RenderTetronimo() {
  glPushMatrix();
  Util.ColorBuffer(TETRONIMO_6_COLOR);
  switch (Tetronimo6.RotationCounter) {
    case 0:
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      break;
    case 1:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare();
      break;
    case 2:
      glTranslatef(-1*unit, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare();
      break;
    case 3:
      glTranslatef(unit, -1*unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare();
      break;
  }
  glPopMatrix();
}

void Tetronimo_6::RenderOutline(int TopRow) {
  glPushMatrix();
  switch(Tetronimo6.RotationCounter) {
    case 0:
      glTranslatef(unit, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 1:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 2:
      glTranslatef(-1*unit, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
    case 3:
      glTranslatef(unit, -1*unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      glTranslatef(0.0f, unit, 0.0f);
      Util.OutlineSquare(TopRow);
      break;
  }
  glPopMatrix();
}

bool Tetronimo_6::InWindowLeft(){
  switch (Tetronimo6.RotationCounter) {
    case 0:
      return col >= 3;
      break;
    case 1:
      return col >= 3;
      break;
    case 2:
      return col >= 3;
      break;
    case 3:
      return col >= 2;
      break;
    }
}

bool Tetronimo_6::InWindowRight() {
  switch (Tetronimo6.RotationCounter) {
    case 0:
      return col <= 8;
      break;
    case 1:
      return col <= 9;
      break;
    case 2:
      return col <= 8;
      break;
    case 3:
      return col <= 8;
      break;
    }
}

void Tetronimo_6::FillBlocks(){
  switch (Tetronimo6.RotationCounter) {
    case 0:
      blocks[col-1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col+1][row-1] = 1;
      blocks[col+1][row] = 1;
      break;
    case 1:
      blocks[col][row-2] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row] = 1;
      blocks[col-1][row] = 1;
      break;
    case 2:
      blocks[col-1][row-2] = 1;
      blocks[col-1][row-1] = 1;
      blocks[col][row-1] = 1;
      blocks[col+1][row-1] = 1;
      break;
    case 3:
      blocks[col+1][row-2] = 1;
      blocks[col][row-2] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row] = 1;
      break;
  }
}

void Tetronimo_6::FillColors(){
  switch (Tetronimo6.RotationCounter) {
    case 0:
      colors[col-1][row-1] = TETRONIMO_6_COLOR;
      colors[col][row-1] = TETRONIMO_6_COLOR;
      colors[col+1][row-1] = TETRONIMO_6_COLOR;
      colors[col+1][row] = TETRONIMO_6_COLOR;
      break;
    case 1:
      colors[col-1][row] = TETRONIMO_6_COLOR;
      colors[col][row] = TETRONIMO_6_COLOR;
      colors[col][row-1] = TETRONIMO_6_COLOR;
      colors[col][row-2] = TETRONIMO_6_COLOR;
      break;
    case 2:
      colors[col-1][row-2] = TETRONIMO_6_COLOR;
      colors[col-1][row-1] = TETRONIMO_6_COLOR;
      colors[col][row-1] = TETRONIMO_6_COLOR;
      colors[col+1][row-1] = TETRONIMO_6_COLOR;
      break;
    case 3:
      colors[col+1][row-2] = TETRONIMO_6_COLOR;
      colors[col][row-2] = TETRONIMO_6_COLOR;
      colors[col][row-1] = TETRONIMO_6_COLOR;
      colors[col][row] = TETRONIMO_6_COLOR;
      break;
  }
}

/* Collision functions return true if a potential collision is detected */
// note that pivot coordinates are blocks[col][row]
bool Tetronimo_6::CheckCollisionRight() {
  switch (Tetronimo6.RotationCounter){
    case 0:
      if(blocks[col+2][row] == 1 || blocks[col+2][row+1] == 1) {
        return true;
      }
      break;
    case 1:
      if(blocks[col+1][row-1] == 1 || blocks[col+1][row] == 1
      || blocks[col+1][row+1] == 1){
        return true;
      }
      break;
    case 2:
      if(blocks[col][row-1] == 1 || blocks[col+2][row] == 1){
        return true;
      }
      break;
    case 3:
      if(blocks[col+1][row+1] == 1 || blocks[col+1][row] == 1
      || blocks[col+2][row-1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// note that pivot coordinates are blocks[col][row]
bool Tetronimo_6::CheckCollisionLeft() {
  switch (Tetronimo6.RotationCounter) {
    case 0:
      if(blocks[col-2][row] == 1 || blocks[col][row+1] == 1){
        return true;
      }
      break;
    case 1:
      if(blocks[col-2][row+1] == 1 || blocks[col-1][row] == 1
      || blocks[col-1][row-1] == 1){
        return true;
      }
      break;
    case 2:
      if(blocks[col-2][row-1] == 1 || blocks[col-2][row] == 1){
        return true;
      }
      break;
    case 3:
      if(blocks[col-1][row-1] == 1 || blocks[col-1][row] == 1
      || blocks[col-1][row+1] == 1){
        return true;
      }
      break;
  }
  return false;
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_6::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

// if any condition for stacking is detected, returns true
bool Tetronimo_6::StackingCriteria(){
  switch (Tetronimo6.RotationCounter) {
    case 0:
      if (row >= 20 || blocks[col-1][row] == 1 || blocks[col][row] == 1
      || blocks[col+1][row+1] == 1) {
        return true;
      }
      break;
    case 1:
      if (row >= 20 || blocks[col-1][row+1] == 1 || blocks[col][row+1] == 1) {
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
      if (row >= 20 || blocks[col][row+1] == 1 || blocks[col+1][row-1] == 1) {
        return true;
      }
      break;
    }
      return false;
}
