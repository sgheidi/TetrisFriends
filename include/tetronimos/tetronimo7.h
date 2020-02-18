#ifndef TETRONIMO7_H
#define TETRONIMO7_H

class Tetronimo_7 {

	public:

		void RenderTetronimo();
		void RenderOutline(int TopRow);

		bool InWindowRight();
		bool InWindowLeft();

		// fills arrays for 'dropped' tetronimos
		void FillBlocks();
		void FillColors();

		void OutlineBlocks(int NewRow);

		void FillArrays();

		// collision detection functions
		bool CheckCollisionRight();
		bool CheckCollisionLeft();

		// stacking
		// returns true if a stacking criteria is detected
		bool StackingCriteria();

};

extern Tetronimo_7 Tetronimo7;

#endif // TETRONIMO7_H
