#include "../include/utility.h"
#include "../include/common.h"

void Tetronimo_2::RenderTetronimo() {
  glPushMatrix();
  switch(Tetronimo2.RotationCounter) {
    case 0:
      Util.DrawSquare(1);
      glTranslatef(-1*unit, unit, 0.0f);
      Util.DrawSquare(2);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare(4);
      glTranslatef(unit, 0.0f, 0.0f);
      Util.DrawSquare(3);
      break;
    case 1:
      glTranslatef(-1*unit, unit, 0.0f);
      Util.DrawSquare(1);
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare(2);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare(4);
      glTranslatef(0.0f, -1*unit, 0.0f);
      Util.DrawSquare(3);
      break;
    case 2:
      glTranslatef(0.0f, 2*unit, 0.0f);
      Util.DrawSquare(1);
      glTranslatef(unit, -1*unit, 0.0f);
      Util.DrawSquare(2);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare(4);
      glTranslatef(-1*unit, 0.0f, 0.0f);
      Util.DrawSquare(3);
      break;
    case 3:
      glTranslatef(unit, unit, 0.0f);
      Util.DrawSquare(1);
      glTranslatef(-1*unit, -1*unit, 0.0f);
      Util.DrawSquare(2);
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare(4);
      glTranslatef(0.0f, unit, 0.0f);
      Util.DrawSquare(3);
      break;
  }
  glPopMatrix();
}

void Tetronimo_2::ResetUnits(){
  x = unit*5;
  y= 0;
  row = 2;
  col = 7;
}

bool Tetronimo_2::InWindowLeft(){
  switch (Tetronimo2.RotationCounter) {
    case 0:
      return col >= 4;
      break;
    case 1:
      return col >= 4;
      break;
    case 2:
      return col >= 4;
      break;
    case 3:
      return col >= 3;
      break;
    }
}

bool Tetronimo_2::InWindowRight() {
  switch (Tetronimo2.RotationCounter) {
    case 0:
      return col <= 9;
      break;
    case 1:
      return col <= 10;
      break;
    case 2:
      return col <= 9;
      break;
    case 3:
      return col <= 9;
      break;
    }
}

void Tetronimo_2::FillBlocks(){
  switch (Tetronimo2.RotationCounter) {
    case 0:
      blocks[col][row-1] = 1;
      blocks[col-1][row-2] = 1;
      blocks[col-1][row-1] = 1;
      blocks[col-2][row-1] = 1;
      break;
    case 1:
      blocks[col-1][row] = 1;
      blocks[col][row+1] = 1;
      blocks[col][row] = 1;
      blocks[col][row-1] = 1;
      break;
    case 2:
      blocks[col][row+1] = 1;
      blocks[col+1][row] = 1;
      blocks[col][row] = 1;
      blocks[col-1][row] = 1;
      break;
    case 3:
      blocks[col+1][row] = 1;
      blocks[col][row-1] = 1;
      blocks[col][row] = 1;
      blocks[col][row+1] = 1;
      break;
  }
}

void Tetronimo_2::FillColors(){
  switch (Tetronimo2.RotationCounter) {
    case 0:
      colors[col][row-1] = 4;
      colors[col-1][row-2] = 1;
      colors[col-1][row-1] = 3;
      colors[col-2][row-1] = 2;
      break;
    case 1:
      colors[col-1][row] = 1;
      colors[col][row+1] = 2;
      colors[col][row] = 3;
      colors[col][row-1] = 4;
      break;
    case 2:
      colors[col][row+1] = 1;
      colors[col+1][row] = 2;
      colors[col][row] = 3;
      colors[col-1][row] = 4;
      break;
    case 3:
      colors[col+1][row] = 1;
      colors[col][row-1] = 2;
      colors[col][row] = 3;
      colors[col][row+1] = 4;
      break;
  }
}

/* Collision functions return true if a potential collision is detected */
bool Tetronimo_2::CheckCollisionRight() {
  switch (Tetronimo2.RotationCounter){
    case 0:
      if(blocks[col+1][row] == 1 || blocks[col+1][row+1] == 1
      || blocks[col+1][row+2] == 1
      || blocks[col+1][row+3] == 1) {
        return true;
      }
      return false;
      break;
    case 1:
      if(blocks[col+2][row] == 1){
        return true;
      }
      return false;
      break;
    case 2:
      if(blocks[col+2][row] == 1){
        return true;
      }
      return false;
      break;
    case 3:
      if(blocks[col+2][row] == 1){
        return true;
      }
      return false;
      break;
  }
}

bool Tetronimo_2::CheckCollisionLeft() {
  switch (Tetronimo2.RotationCounter) {
    case 0:
      if(blocks[col-1][row] == 1 || blocks[col-1][row+1] == 1
      || blocks[col-1][row+2] == 1
      || blocks[col-1][row+3] == 1){
        return true;
      }
      return false;
      break;
    case 1:
      if(blocks[col-3][row] == 1){
        return true;
      }
      return false;
      break;
    case 2:
      if(blocks[col-3][row] == 1){
        return true;
      }
      return false;
      break;
    case 3:
      if(blocks[col-3][row] == 1){
        return true;
      }
      return false;
      break;
  }
}

// Fill blocks and colors
// Used when a tetronimo 'drops' on board
void Tetronimo_2::FillArrays() {
  this->FillBlocks();
  this->FillColors();
}

bool Tetronimo_2::LandingCriteria(){
  switch(Tetronimo2.RotationCounter){
    case 0:
        if (row >= 21 || blocks[col][row+1] == 1 || blocks[col-1][row+1] == 1
        || blocks[col-2][row+1] == 1) {
          return true;
        }
        break;
      case 1:
        if (row >= 20 || blocks[col-2][row+2] == 1 || blocks[col-1][row+2] == 1
        || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
          return true;
        }
        break;
      // case 2:
      //   if (row >= 20 || blocks[col-2][row+1] == 1 || blocks[col-1][row+1] == 1
      //   || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
      //     return true;
      //   }
      //   break;
      // case 3:
      //   if (row >= 20 || blocks[col-2][row+1] == 1 || blocks[col-1][row+1] == 1
      //   || blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
      //     return true;
      //   }
      //   break;
    }
      return false;
}
