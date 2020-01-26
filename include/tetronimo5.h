#ifndef TETRONIMO5_H
#define TETRONIMO5_H

class Tetronimo_5 {

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

extern Tetronimo_5 Tetronimo5;

#endif // TETRONIMO5_H
