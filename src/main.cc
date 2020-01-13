#include "../include/common.h"

Utility Util;
Tetronimo_1 Tetronimo1;
Tetronimo_2 Tetronimo2;
Board GameBoard;

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

int main(void) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(ScreenX, ScreenY, "Fruit Tetris", NULL, NULL);
	glfwSetWindowPos(window, 650, 80);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, inputK);
	srand(time(NULL));
	// random number is the Tetronimo piece number chosen from 1-6
	Rand = 2;

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		 NumberOfIterations ++;
		 GameBoard.DrawBoard();
		 GameBoard.RenderDroppedBlocks();

		 switch(Rand){

			/* Tetronimo 1 */
			case 1:
				Tetronimo1.RenderTetronimo();
				// timer function
				if(NumberOfIterations % GameSpeed == 0 && Paused == false){
					NumberOfIterations = 0;
					Util.GoDown();
				}
				// Landing criteria
				if(Tetronimo1.LandingCriteria() == true) {
					Tetronimo1.FillArrays();
					Tetronimo1.RotationCounter = 0;
					Rand = 1;
					GameBoard.DoLineClear();
				}
				break;

			/* Tetronimo 2 */
			case 2:
				Tetronimo2.RenderTetronimo();
				// timer function
				if(NumberOfIterations % GameSpeed == 0 && Paused == false){
					NumberOfIterations = 0;
					Util.GoDown();
				}
				// check for stacking (start new block)
				if (Tetronimo2.LandingCriteria() == true) {
					Tetronimo2.FillArrays();
					Tetronimo2.RotationCounter = 0;
					Rand = 2;
					GameBoard.DoLineClear();
				}
				break;
		}

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
