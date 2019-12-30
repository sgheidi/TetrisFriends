#ifndef TETRONIMO1_H
#define TETRONIMO1_H

class Tetronimo_1 {

	public:

		int RotationCounter;

		void RenderTetronimo();

		bool InWindowLeft();
		bool InWindowRight();

		// fills arrays for 'dropped' tetronimos
		void FillBlocks();
		void FillColors();

		void FillArrays();

		// collision detection functions
		bool CheckCollisionRight();
		bool CheckCollisionLeft();

		// stacking
		// returns true if a landing criteria is detected
		bool LandingCriteria();

};

extern Tetronimo_1 Tetronimo1;

#endif
