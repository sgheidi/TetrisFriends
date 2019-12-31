#include "../include/common.h"

/* input handling & collision detection here */

void inputK(GLFWwindow* window, int key, int scancode, int action, int mods) {

	switch(Rand) {

			/* Tetronimo 1 */
			case 1:
				/* collision detection with horizontal movement */
						// right side
						if (action != GLFW_RELEASE) {
							if (key == GLFW_KEY_RIGHT && Tetronimo1.InWindowRight() && Paused == false
							&& Tetronimo1.CheckCollisionRight() == false){
								Util.GoRight();
							}
						}
						// left side
						if (action != GLFW_RELEASE) {
							if (key == GLFW_KEY_LEFT && Tetronimo1.InWindowLeft() && Paused == false
						&& Tetronimo1.CheckCollisionLeft() == false){
								Util.GoLeft();
							}
						}

						// rotatations
						if (action != GLFW_RELEASE) {
							if (key == GLFW_KEY_UP && Paused == false){
								if(Tetronimo1.RotationCounter == 1) {
									Tetronimo1.RotationCounter = 0;
								}
								else if(Tetronimo1.RotationCounter == 0) {
									Tetronimo1.RotationCounter = 1;
								}
							}
						}
				break;

			/* Tetronimo 2 */
			case 2:

				/* collision detection with horizontal movement */
						// right side
						if (action != GLFW_RELEASE) {
							if (key == GLFW_KEY_RIGHT && Tetronimo2.InWindowRight() && Paused == false
							&& Tetronimo2.CheckCollisionRight() == false){
								Util.GoRight();
							}
						}
						// left side
						if (action != GLFW_RELEASE) {
							if (key == GLFW_KEY_LEFT && Tetronimo2.InWindowLeft() && Paused == false
						&& Tetronimo2.CheckCollisionLeft() == false){
								Util.GoLeft();
							}
						}
				// rotatations
				if (action != GLFW_RELEASE) {
					if (key == GLFW_KEY_UP && Paused == false){
						if(Tetronimo2.RotationCounter < 3) {
							Tetronimo2.RotationCounter ++;
						}
						else if(Tetronimo2.RotationCounter >= 3) {
							Tetronimo2.RotationCounter = 0;
						}
					}
				}
				break;
	}



// acceleration
	if (action != GLFW_RELEASE) {
		if (key == GLFW_KEY_DOWN && Paused == false){
			Util.AccelerateDown();
		}
	}

	// pause
	if (action != GLFW_RELEASE) {
		if (key == GLFW_KEY_P && Paused == false){
			Paused = true;
		}
		else if (key == GLFW_KEY_P && Paused == true) {
			Paused = false;
		}
	}


	// quit
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
	if(action != GLFW_RELEASE && key == GLFW_KEY_Q) {
			glfwDestroyWindow(window);
			glfwTerminate();
			exit(EXIT_SUCCESS);
		}

}
