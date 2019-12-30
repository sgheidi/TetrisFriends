#ifndef TETRONIMO2_H
#define TETRONIMO2_H

class Tetronimo_2 {

	public:

		int RotationCounter;

		void RenderTetronimo();

		bool InWindowRight();

		bool InWindowLeft();

		void FillBlocks();

		void FillColors();

		bool CheckCollisionRight();

		bool CheckCollisionLeft();

		void FillArrays();

		bool LandingCriteria();

};

extern Tetronimo_2 Tetronimo2;

#endif
