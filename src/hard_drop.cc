#include "../include/common.h"

/*
 * This function handles 'hard-dropping' tetronimos
 * which can be done by pressing 'Space' key.
 *
 * Procedure: Find the highest row between the pivot's
 * columns in the current tetronimo. Then, make a minor
 * adjustment according to the surrounding free/filled blocks.
 * Calculate the new pivot position based on this.
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
             if (blocks[col][row+1] == 0 && blocks[col-1][row+1] == 1) {
               row += 2;
             }
             break;
         }
         Tetronimo5.FillArrays();
         Tetronimo5.RotationCounter = 0;
         break;

       /* Tetronimo 6 */
      case 6:
         switch (Tetronimo6.RotationCounter) {
           case 0:
             TopRow = Util.FindTopRow_Between(col-1, col+1);
             row = TopRow;
             if ((blocks[col][row+1] == 1 && blocks[col+1][row+1] == 0)
             || (blocks[col-1][row+1] == 1 && blocks[col+1][row+1] == 0)) {
               row ++;
             }
             break;
           case 1:
             TopRow = Util.FindTopRow_Between(col-1, col);
             row = TopRow;
             break;
           case 2:
             TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
             row = TopRow;
             break;
           case 3:
             TopRow = Util.FindTopRow_Between(col, col+1);
             row = TopRow;
             if (blocks[col][row+1] == 0 && blocks[col+1][row+1] == 1) {
               row += 2;
             }
             break;
         }
         Tetronimo6.FillArrays();
         Tetronimo6.RotationCounter = 0;
         break;

       /* Tetronimo 7 */
       case 7:
          TopRow = Util.FindTopRow_Between(col, col+1);
          row = TopRow;
          Tetronimo7.FillArrays();
          break;
  }
  Rand = (rand()%7)+1;
  if (Testing) Rand = TestRand;
  GameBoard.ResetUnits();
  GameBoard.LineClear();
}

/* Colors the tiles (grey) in which the current tetronimo
 * would drop if player hard-dropped.
 *
 * Works similar to above but instead of filling arrays,
 * only fills the color array with grey color. Does not
 * modify 'blocks' array.
 */

void Hard_Drop::OutlineTetronimo() {
  int TopRow = 0;
  switch (Rand) {

        /* Tetronimo 1 */
        case 1:
           switch (Tetronimo1.RotationCounter) {
             case 0:
               TopRow = Util.FindTopRow_Single(col) - 1;
               break;
             case 1:
               TopRow = Util.FindTopRow_Between(col-2, col+1) + 1;
               break;
           }
           Tetronimo1.RenderOutline(TopRow-1);
           break;

           /* Tetronimo 2 */
          case 2:
             switch (Tetronimo2.RotationCounter) {
               case 0:
                 TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
                 break;
               case 1:
                 TopRow = Util.FindTopRow_Between(col-1, col);
                 if (blocks[col-1][row] == 0 && blocks[col][row+1] == 0) {
                   row ++;
                 }
                 break;
               case 2:
                 TopRow = Util.FindTopRow_Between(col-1, col+1);
                 if (blocks[col][row+1] == 0) {
                   row ++;
                 }
                 break;
               case 3:
                 TopRow = Util.FindTopRow_Between(col, col+1);
                 if (blocks[col+1][row] == 0 && blocks[col][row+1] == 0) {
                   row ++;
                 }
                 break;
             }
             break;

           /* Tetronimo 3 */
          case 3:
             switch (Tetronimo3.RotationCounter) {
               case 0:
                 TopRow = Util.FindTopRow_Between(col-1, col+1);
                 if (blocks[col][row+1] == 0 && blocks[col-1][row+1] == 0 && blocks[col+1][row+1] == 1) {
                   row ++;
                 }
                 break;
               case 1:
                 TopRow = Util.FindTopRow_Between(col, col+1);
                 if (blocks[col+1][row+1] == 0 && blocks[col][row+1] == 1) {
                   row ++;
                 }
                 break;
             }
             break;

           /* Tetronimo 4 */
          case 4:
             switch (Tetronimo4.RotationCounter) {
               case 0:
                 TopRow = Util.FindTopRow_Between(col-1, col+1);
                 if (blocks[col][row+1] == 0 && blocks[col+1][row+1] == 0 && blocks[col-1][row+1] == 1) {
                   row ++;
                 }
                 break;
               case 1:
                 TopRow = Util.FindTopRow_Between(col-1, col);
                 if (blocks[col-1][row+1] == 0 && blocks[col][row+1] == 1) {
                   row ++;
                 }
                 break;
             }
             break;

           /* Tetronimo 5 */
          case 5:
             switch (Tetronimo5.RotationCounter) {
               case 0:
                 TopRow = Util.FindTopRow_Between(col-1, col+1);
                 if ((blocks[col-1][row+1] == 0 && blocks[col][row+1] == 1 && blocks[col+1][row+1] == 1)
                 || (blocks[col+1][row+1] == 1 && blocks[col][row+1] == 0)) {
                   row ++;
                 }
                 break;
               case 1:
                 TopRow = Util.FindTopRow_Between(col, col+1);
                 break;
               case 2:
                 TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
                 break;
               case 3:
                 TopRow = Util.FindTopRow_Between(col-1, col);
                 if (blocks[col][row+1] == 0 && blocks[col-1][row+1] == 1) {
                   row += 2;
                 }
                 break;
             }
             break;

           /* Tetronimo 6 */
          case 6:
             switch (Tetronimo6.RotationCounter) {
               case 0:
                 TopRow = Util.FindTopRow_Between(col-1, col+1);
                 if ((blocks[col][row+1] == 1 && blocks[col+1][row+1] == 0)
                 || (blocks[col-1][row+1] == 1 && blocks[col+1][row+1] == 0)) {
                   row ++;
                 }
                 break;
               case 1:
                 TopRow = Util.FindTopRow_Between(col-1, col);
                 break;
               case 2:
                 TopRow = Util.FindTopRow_Between(col-1, col+1) + 1;
                 break;
               case 3:
                 TopRow = Util.FindTopRow_Between(col, col+1);
                 if (blocks[col][row+1] == 0 && blocks[col+1][row+1] == 1) {
                   row += 2;
                 }
                 break;
             }
             break;

       /* Tetronimo 7 */
       case 7:
          TopRow = Util.FindTopRow_Between(col, col+1);
          Tetronimo7.RenderOutline(TopRow);
          break;
  }
}
