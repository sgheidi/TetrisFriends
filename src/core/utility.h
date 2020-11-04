#ifndef UTILITY_H
#define UTILITY_H

class Utility {
public:
	void test();
	void GoDown();
	void AccelerateDown();
	void GoRight();
	void GoLeft();
	void ColorBuffer(int color);
	void DrawSquare();
	void OutlineSquare(int _row_);
	void ZeroArrays();
	int FindTopRow_Single(int x);
	int FindTopRow_Between(int StartCol, int EndCol);
	void PrintFilledBlocks();
	void PrintCurrentPosition();
};

extern Utility Util;

#endif // UTILITY_H
