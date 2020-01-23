#ifndef TETRONIMO2_H
#define TETRONIMO2_H

class Tetronimo_2 {

	public:

		int RotationCounter;

		void RenderTetronimo();

		bool InWindowRight();
		bool InWindowLeft();

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

extern Tetronimo_2 Tetronimo2;

#endif
