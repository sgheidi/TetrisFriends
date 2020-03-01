#include "../include/common.h"

/* use a simple queue to serve current & next tetronimos */

void _queue_::Init() {
  for (int i=0;i<4;i++) {
    Rand[i] = (rand()%7)+1;
  }
}

void _queue_::ClearAllColors() {
  for (int i=1;i<=4;i++) {
    for (int j=0;j<=4;j++) {
      Next.colors1[i][j] = 0;
      Next.colors2[i][j] = 0;
      Next.colors3[i][j] = 0;
      Next.colors4[i][j] = 0;
    }
  }
}

// serves the next tetronimo
void _queue_::ServeNext() {
  for (int i=1;i<4;i++) {
    Rand[i-1] = Rand[i];
  }
  Rand[3] = (rand()%7)+1;
}

// only load 1 tetronimo
void _queue_::SetTestRand() {
  for (int i=0;i<4;i++) {
    Rand[i] = TestRand;
  }
}

void _queue_::UpdateNextColors() {
  this->ClearAllColors();
  switch (Rand[1]) {
    case 1:
      for (int i=1;i<=4;i++) {
        Next.colors1[i][3] = TETRONIMO_1_COLOR;
      }
      break;
    case 2:
      for (int i=1;i<=3;i++) {
        Next.colors1[i][3] = TETRONIMO_2_COLOR;
      }
      Next.colors1[2][2] = TETRONIMO_2_COLOR;
      break;
    case 3:
      Next.colors1[2][3] = TETRONIMO_3_COLOR;
      Next.colors1[3][3] = TETRONIMO_3_COLOR;
      Next.colors1[3][2] = TETRONIMO_3_COLOR;
      Next.colors1[4][2] = TETRONIMO_3_COLOR;
      break;
    case 4:
      Next.colors1[3][3] = TETRONIMO_4_COLOR;
      Next.colors1[2][3] = TETRONIMO_4_COLOR;
      Next.colors1[2][2] = TETRONIMO_4_COLOR;
      Next.colors1[1][2] = TETRONIMO_4_COLOR;
      break;
    case 5:
      Next.colors1[2][3] = TETRONIMO_5_COLOR;
      Next.colors1[2][2] = TETRONIMO_5_COLOR;
      Next.colors1[3][2] = TETRONIMO_5_COLOR;
      Next.colors1[4][2] = TETRONIMO_5_COLOR;
      break;
    case 6:
      Next.colors1[3][3] = TETRONIMO_6_COLOR;
      Next.colors1[2][3] = TETRONIMO_6_COLOR;
      Next.colors1[2][2] = TETRONIMO_6_COLOR;
      Next.colors1[2][1] = TETRONIMO_6_COLOR;
      break;
    case 7:
      Next.colors1[2][2] = TETRONIMO_7_COLOR;
      Next.colors1[3][2] = TETRONIMO_7_COLOR;
      Next.colors1[3][3] = TETRONIMO_7_COLOR;
      Next.colors1[2][3] = TETRONIMO_7_COLOR;
      break;
  }
}

// use for testing
void _queue_::PrintQueue() {
  for (int i=0;i<4;i++) {
    std::cout << Rand[i] << std::endl;
  }
}
