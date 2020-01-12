#ifndef BOARD_H
#define BOARD_H

class Board {

	public:

		void DrawBoard();

		// Draws blocks that have already landed
		void RenderDroppedBlocks();

		void ResetUnits();

		// Helper functions
		void PrintFilledBlocks();
		void PrintCurrentPosition();

		// line clearing functions
		void ClearLine(int row);
		bool IsRowFull(int row);
		void DoLineClear();

};

extern Board GameBoard;

#endif
