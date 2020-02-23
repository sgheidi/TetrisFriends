#include "../include/common.h"

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

int main(void) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	// left and right side each have 4 blocks across to show 'held' and 'next' pieces
	window = glfwCreateWindow(ScreenX + (10*unit), ScreenY + 1, "Fruit Tetris", NULL, NULL);
	glfwSetWindowPos(window, 650, 80);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, inputK);
	srand(time(NULL));
	// uncomment the following line to test a particular tetronimo
	// Testing = true;
	TestRand = 5;
	// random number is the Tetronimo piece number chosen randomly from 1-7
	Rand = (rand()%7)+1;
	if (Testing) Rand = TestRand;
	GameBoard.Init();

	while (!glfwWindowShouldClose(window)) {
		 glfwPollEvents();
		 Timer.NumIterations ++;
		 GameBoard.DrawGrid();
		 GameBoard.RenderBlocks_Board();
		 GameBoard.RenderBlocks_Hold();

		 switch (Rand) {

			/* Tetronimo 1 */
			case 1:
				Tetronimo1.RenderTetronimo();
				// timer function
				if (Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo1.StackingCriteria() == true) {
					Tetronimo1.FillArrays();
					Tetronimo1.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 2 */
			case 2:
				Tetronimo2.RenderTetronimo();
				// timer function
				if (Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo2.StackingCriteria() == true) {
					Tetronimo2.FillArrays();
					Tetronimo2.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 3 */
			case 3:
				Tetronimo3.RenderTetronimo();
				// timer function
				if(Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo3.StackingCriteria() == true) {
					Tetronimo3.FillArrays();
					Tetronimo3.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 4 */
			case 4:
				Tetronimo4.RenderTetronimo();
				// timer function
				if(Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo4.StackingCriteria() == true) {
					Tetronimo4.FillArrays();
					Tetronimo4.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 5 */
			case 5:
				Tetronimo5.RenderTetronimo();
				// timer function
				if(Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo5.StackingCriteria() == true) {
					Tetronimo5.FillArrays();
					Tetronimo5.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 6 */
			case 6:
				Tetronimo6.RenderTetronimo();
				// timer function
				if(Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo6.StackingCriteria() == true) {
					Tetronimo6.FillArrays();
					Tetronimo6.RotationCounter = 0;
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;

			/* Tetronimo 7 */
			case 7:
				Tetronimo7.RenderTetronimo();
				// timer function
				if (Timer.NumIterations % Timer.GameSpeed == 0 && Paused == false){
					Timer.NumIterations = 0;
					Util.GoDown();
				}
				// stacking criteria
				if (Tetronimo7.StackingCriteria() == true) {
					Tetronimo7.FillArrays();
					Rand = (rand()%7)+1;
					if (Testing) Rand = TestRand;
					GameBoard.ResetUnits();
					LineClearer.LineClear();
				}
				break;
		}
		HardDropper.OutlineTetronimos();

		// if topmost block is full, freeze the game permanently
		// (game over)
		if (blocks[6][1] == 1) {
			Paused = true;
			GameOver = true;
			Rand = -1;
		}

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
