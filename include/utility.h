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

		// Helper functions
		void PrintFilledBlocks();
		void PrintCurrentPosition();
};

extern Utility Util;

#endif
