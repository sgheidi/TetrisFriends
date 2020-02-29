#ifndef TETRONIMO1_H
#define TETRONIMO1_H

class Tetronimo_1 {
private:
	// fills arrays for 'dropped' tetronimos
	void FillBlocks();
	void FillColors();

public:
	int RotationCounter;

	void RenderTetronimo();
	void RenderOutline(int TopRow);

	bool InWindowRight();
	bool InWindowLeft();

	void FillArrays();

	// collision detection functions
	bool CheckCollisionRight();
	bool CheckCollisionLeft();

	// stacking
	// returns true if a stacking criteria is detected
	bool StackingCriteria();
};

extern Tetronimo_1 Tetronimo1;

#endif // TETRONIMO1_H
