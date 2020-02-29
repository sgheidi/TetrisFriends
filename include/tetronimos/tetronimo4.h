#ifndef TETRONIMO4_H
#define TETRONIMO4_H

class Tetronimo_4 {
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

extern Tetronimo_4 Tetronimo4;

#endif // TETRONIMO4_H
