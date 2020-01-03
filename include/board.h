#ifndef BOARD_H
#define BOARD_H

class Board {

	public:

		void DrawBoard();

	  // draws a block that has already landed
		void RenderDroppedBlocks();

		void ResetUnits();

		/* Helper functions */
		void PrintFilledBlocks();
		void PrintCurrentPosition();

		void ClearLine(int row);

		bool IsRowFull(int row);

		void DoLineClear();

};

extern Board GameBoard;

#endif
