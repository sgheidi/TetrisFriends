#ifndef BOARD_H
#define BOARD_H

class Board {

	public:

		void DrawGrid();

		// Draws blocks that have already landed
		void RenderDroppedBlocks();

		// initial setting of row/col (pivot: purple) based on Tetronimo piece (Rand)
		void Init();

		void ResetUnits();

		// line clearing functions
		void ClearLine(int row);
		bool IsRowFull(int row);
		void LineClear();

};

extern Board GameBoard;

#endif
