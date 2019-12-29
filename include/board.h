#ifndef BOARD_H
#define BOARD_H

class Board {

	public:

		void DrawBoard();

	  // draws a block that has already landed
		void RenderDroppedBlocks();

		void ResetUnits();

		// helper function
		void PrintFilledBlocks();

};

extern Board GameBoard;

#endif
