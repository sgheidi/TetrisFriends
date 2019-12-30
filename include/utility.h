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
		void FindColor(int color);

		// draws single block with specified color
		void DrawSquare(int color);

};

extern Utility Util;

#endif
