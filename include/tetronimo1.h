#ifndef TETRONIMO1_H
#define TETRONIMO1_H

class Tetronimo_1 {

	public:

		int RotationCounter;

		void RenderTetronimo();

		bool InWindowLeft();

		bool InWindowRight();

		void FillBlocks();

		void FillColors();

		bool CheckCollisionRight();

		bool CheckCollisionLeft();

		void Fill();
		
};

extern Tetronimo_1 Tetronimo1;

#endif
