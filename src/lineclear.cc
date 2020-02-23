#include "../include/common.h"

void _LineClear_::ClearLine(int row) {
  for (int col=1;col<=10;col++) {
    blocks[col][row] = 0;
    colors[col][row] = 0;
  }
}

bool _LineClear_::IsRowFull(int row) {
  for (int col=1;col<=10;col++) {
    if (blocks[col][row] == 0) {
      return false;
    }
  }
  return true;
}

// y (row) is the row that the lines should be brought down to
// and NumLines is the number of rows they should come down
void _LineClear_::BringLinesDown(int y, int NumLines) {
  for (int x=1;x<=10;x++) {
    for (int vert=y;vert>=1;vert--) {
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
void _LineClear_::LineClear() {
  int TopMostRow = 0;
  int LinesCleared = 0;
  for (int y=20;y>=1;y--) {
    if (this->IsRowFull(y) == true) {
      this->ClearLine(y);
      LinesCleared ++;
      TopMostRow = y-1;
    }
  }
  if (LinesCleared >=1 ) {
    this->BringLinesDown(TopMostRow, LinesCleared);
    if (Timer.GameSpeed > LinesCleared) {
      Timer.GameSpeed -= LinesCleared;
    }
  }
}
