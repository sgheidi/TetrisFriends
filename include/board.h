#ifndef BOARD_H
#define BOARD_H

class Board {

	public:

		void DrawBoard();

		// Draws blocks that have already landed
		void RenderDroppedBlocks();

		// initial setting of row/col (pivot: purple) based on Tetronimo piece (Rand)
		void Init();

		// Helper functions
		void PrintFilledBlocks();
		void PrintCurrentPosition();

		// line clearing functions
		void ClearLine(int row);
		bool IsRowFull(int row);
		void LineClear();

};

extern Board GameBoard;

#endif
