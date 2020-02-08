#ifndef TETRONIMO6_H
#define TETRONIMO6_H

class Tetronimo_6 {

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

extern Tetronimo_6 Tetronimo6;

#endif // TETRONIMO6_H
