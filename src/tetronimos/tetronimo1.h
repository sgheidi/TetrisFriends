#ifndef TETRONIMO1_H
#define TETRONIMO1_H

class Tetronimo_1 {
private:
	void FillBlocks();
	void FillColors();
public:
	int RotationCounter;
	void RenderTetronimo();
	void RenderOutline(int TopRow);
	bool InWindowRight();
	bool InWindowLeft();
	void FillArrays();
	bool CheckCollisionRight();
	bool CheckCollisionLeft();
	bool StackingCriteria();
};

extern Tetronimo_1 Tetronimo1;

#endif // TETRONIMO1_H
