#ifndef UTILITY_H
#define UTILITY_H

class Utility {

	public:

		void GoDown();
		void AccelerateDown();
		void GoRight();
		void GoLeft();

		// maps int to color
		// i.e outputs color with integer input
		void ColorBuffer(int color);

		// draws single block with specified color
		void DrawSquare(int color);

		void ZeroArrays();

		int FindTopRow_Single(int x);
		int FindTopRow_Between(int StartCol, int EndCol);

		// Helper functions
		void PrintFilledBlocks();
		void PrintCurrentPosition();
};

extern Utility Util;

#endif // UTILITY_H
