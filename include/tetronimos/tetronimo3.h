#ifndef Tetronimo3_H
#define Tetronimo3_H

class Tetronimo_3 {

	public:

		int RotationCounter;

		void RenderTetronimo();
		void RenderOutline(int TopRow);

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
		// returns true if a stacking criteria is detected
		bool StackingCriteria();

};

extern Tetronimo_3 Tetronimo3;

#endif // TETRONIMO3_H
