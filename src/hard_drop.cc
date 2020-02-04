#include "../include/common.h"

/*
 * this function handles 'hard-dropping' tetronimos
 * which can be done by pressing 'Space' key
 */

// note that pivot is blocks[col][row-1]
void Hard_Drop::HardDrop() {
  int TopRow = 0;
  switch (Rand) {

    /* Tetronimo 1 */
    case 1:
       switch (Tetronimo1.RotationCounter) {
         case 0:
           TopRow = Util.FindTopRow_Single(col) - 1;
           row = TopRow;
           break;
         case 1:
           TopRow = Util.FindTopRow_Between(col-2, col+1) + 1;
           row = TopRow;
           break;
       }
       Tetronimo1.FillArrays();
       Tetronimo1.RotationCounter = 0;
       break;

       /* Tetronimo 2 */
      case 2:
         switch (Tetronimo2.RotationCounter) {
           case 0:
             TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
             row = TopRow;
             break;
           case 1:
             TopRow = Util.FindTopRow_Between(col-1, col);
             row = TopRow;
             if (blocks[col-1][row] == 0 && blocks[col][row+1] == 0) {
               row ++;
             }
             break;
           case 2:
             TopRow = Util.FindTopRow_Between(col-1, col+1);
             row = TopRow;
             if (blocks[col][row+1] == 0) {
               row ++;
             }
             break;
           case 3:
             TopRow = Util.FindTopRow_Between(col, col+1);
             row = TopRow;
             if (blocks[col+1][row] == 0 && blocks[col][row+1] == 0) {
               row ++;
             }
             break;
         }
         Tetronimo2.FillArrays();
         Tetronimo2.RotationCounter = 0;
         break;

       /* Tetronimo 3 */
      case 3:
         switch (Tetronimo3.RotationCounter) {
           case 0:
             TopRow = Util.FindTopRow_Between(col-1, col+1);
             row = TopRow;
             if (blocks[col][row+1] == 0 && blocks[col-1][row+1] == 0 && blocks[col+1][row+1] == 1) {
               row ++;
             }
             break;
           case 1:
             TopRow = Util.FindTopRow_Between(col, col+1);
             row = TopRow;
             if (blocks[col+1][row+1] == 0 && blocks[col][row+1] == 1) {
               row ++;
             }
             break;
         }
         Tetronimo3.FillArrays();
         Tetronimo3.RotationCounter = 0;
         break;

       /* Tetronimo 4 */
      case 4:
         switch (Tetronimo4.RotationCounter) {
           case 0:
             TopRow = Util.FindTopRow_Between(col-1, col+1);
             row = TopRow;
             if (blocks[col][row+1] == 0 && blocks[col+1][row+1] == 0 && blocks[col-1][row+1] == 1) {
               row ++;
             }
             break;
           case 1:
             TopRow = Util.FindTopRow_Between(col-1, col);
             row = TopRow;
             if (blocks[col-1][row+1] == 0 && blocks[col][row+1] == 1) {
               row ++;
             }
             break;
         }
         Tetronimo4.FillArrays();
         Tetronimo4.RotationCounter = 0;
         break;

       /* Tetronimo 5 */
      case 5:
         switch (Tetronimo5.RotationCounter) {
           case 0:
             TopRow = Util.FindTopRow_Between(col-1, col+1);
             row = TopRow;
             if ((blocks[col-1][row+1] == 0 && blocks[col][row+1] == 1 && blocks[col+1][row+1] == 1)
           || (blocks[col+1][row+1] == 1 && blocks[col][row+1] == 0)) {
               row ++;
             }
             break;
           case 1:
             TopRow = Util.FindTopRow_Between(col, col+1);
             row = TopRow;
             break;
           case 2:
             TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
             row = TopRow;
             break;
           case 3:
             TopRow = Util.FindTopRow_Between(col-1, col);
             row = TopRow;
             // if (blocks[col-1][row+1] == 0 && blocks[col][row+1] == 1) {
             //   row ++;
             // }
             break;
         }
         Tetronimo5.FillArrays();
         Tetronimo5.RotationCounter = 0;
         break;
  }
  Rand = (rand()%7)+1;
  if (Testing) Rand = TestRand;
  GameBoard.ResetUnits();
  GameBoard.LineClear();
}

// colors the tiles (grey) in which the current tetronimo
// would drop if player hard-dropped
void Hard_Drop::Outline() {

}
