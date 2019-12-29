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
	Rand = 1;

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
				// check for stacking (start new block)
				switch(Tetronimo1.RotationCounter){
					case 0:
							if (row >= 18 || blocks[col][row+3] == 1) {
								Tetronimo1.Fill();
								Tetronimo1.RotationCounter = 0;
								Rand = 1;
								// GameBoard.CheckLineClear();
								}
								break;
						case 1:
							if (row >= 20 || blocks[col-2][row+1] == 1 || blocks[col-1][row+1] == 1
								|| blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
								Tetronimo1.Fill();
								Tetronimo1.RotationCounter = 0;
								Rand = 1;
								// GameBoard.CheckLineClear();
							}
							break;
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
				switch(Tetronimo2.RotationCounter){
					case 0:
								if (row >= 18 || blocks[col][row+3] == 1) {
									Tetronimo2.Fill();
									Tetronimo2.RotationCounter = 0;
									Rand = 2;
									// GameBoard.CheckLineClear();
								}
								break;
						case 1:
								if (row >= 20 || blocks[col-2][row+1] == 1 || blocks[col-1][row+1] == 1
									|| blocks[col][row+1] == 1 || blocks[col+1][row+1] == 1) {
									Tetronimo2.Fill();
									Tetronimo2.RotationCounter = 0;
									Rand = 2;
									// GameBoard.CheckLineClear();
								}
								break;
				}
					break;
		}



		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
