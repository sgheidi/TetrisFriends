#ifndef BOARD_H
#define BOARD_H

class Board {

	public:
		int InQueue = 0;
		void Horizontal(int startX, int endX, int startY, int endY);
		void Vertical(int startX, int endX, int startY, int endY);
		void DrawGrid();

		// Draws blocks that have already landed
		void RenderBlocks_Board();
		void RenderBlocks_Hold();

		// initial setting of row/col (pivot: purple) based on Tetronimo piece (Rand)
		void Init();

		void ResetUnits();
		
		void SwitchTetronimo();
};

extern Board GameBoard;

#endif // BOARD_H
