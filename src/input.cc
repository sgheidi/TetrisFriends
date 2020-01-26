#include "../include/common.h"

/* input handling & collision detection here */

void inputK(GLFWwindow* window, int key, int scancode, int action, int mods) {

	switch(Rand) {

		/* Tetronimo 1 */
		case 1:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo1.InWindowRight()
				&& Tetronimo1.CheckCollisionRight() == false) {
						Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo1.InWindowLeft()
				&& Tetronimo1.CheckCollisionLeft() == false) {
						Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
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
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo2.InWindowRight()
				&& Tetronimo2.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo2.InWindowLeft()
				&& Tetronimo2.CheckCollisionLeft() == false) {
					Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
					if(Tetronimo2.RotationCounter < 3) {
						Tetronimo2.RotationCounter ++;
					}
					else if(Tetronimo2.RotationCounter >= 3) {
						Tetronimo2.RotationCounter = 0;
					}
				}
			}
			break;

		/* Tetronimo 3 */
		case 3:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo3.InWindowRight()
				&& Tetronimo3.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo3.InWindowLeft()
				&& Tetronimo3.CheckCollisionLeft() == false) {
					Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
					if(Tetronimo3.RotationCounter == 1) {
						Tetronimo3.RotationCounter = 0;
					}
					else if(Tetronimo3.RotationCounter == 0) {
						Tetronimo3.RotationCounter = 1;
					}
				}
			}
			break;

		/* Tetronimo 4 */
		case 4:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo4.InWindowRight()
				&& Tetronimo4.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo4.InWindowLeft()
				&& Tetronimo4.CheckCollisionLeft() == false) {
					Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
					if(Tetronimo4.RotationCounter == 1) {
						Tetronimo4.RotationCounter = 0;
					}
					else if(Tetronimo4.RotationCounter == 0) {
						Tetronimo4.RotationCounter = 1;
					}
				}
			}
			break;

		/* Tetronimo 5 */
		case 5:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo5.InWindowRight()
				&& Tetronimo5.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo5.InWindowLeft()
				&& Tetronimo5.CheckCollisionLeft() == false) {
					Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
					if(Tetronimo5.RotationCounter < 3) {
						Tetronimo5.RotationCounter ++;
					}
					else if(Tetronimo5.RotationCounter >= 3) {
						Tetronimo5.RotationCounter = 0;
					}
				}
			}
			break;

		/* Tetronimo 6 */
		case 6:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo6.InWindowRight()
				&& Tetronimo6.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo6.InWindowLeft()
				&& Tetronimo6.CheckCollisionLeft() == false) {
					Util.GoLeft();
				}
				// rotatations
				else if (key == GLFW_KEY_UP) {
					if(Tetronimo6.RotationCounter < 3) {
						Tetronimo6.RotationCounter ++;
					}
					else if(Tetronimo6.RotationCounter >= 3) {
						Tetronimo6.RotationCounter = 0;
					}
				}
			}
			break;

		/* Tetronimo 7 */
		case 7:
			if (action != GLFW_RELEASE && Paused == false) {
				// right side collision check
				if (key == GLFW_KEY_RIGHT && Tetronimo7.InWindowRight()
				&& Tetronimo7.CheckCollisionRight() == false) {
					Util.GoRight();
				}
				// left side collision check
				else if (key == GLFW_KEY_LEFT && Tetronimo7.InWindowLeft()
				&& Tetronimo7.CheckCollisionLeft() == false) {
					Util.GoLeft();
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

	// reset
	if (action != GLFW_RELEASE && key == GLFW_KEY_R) {
		switch (Rand) {
			case 1:
				Tetronimo1.RotationCounter = 0;
			case 2:
				Tetronimo2.RotationCounter = 0;
			case 3:
				Tetronimo3.RotationCounter = 0;
			case 4:
				Tetronimo4.RotationCounter = 0;
			case 5:
				Tetronimo5.RotationCounter = 0;
			case 6:
				Tetronimo6.RotationCounter = 0;
		}
		Rand = (rand()%7)+1;
		GameBoard.ResetUnits();
		Util.ZeroArrays();
		GameBoard.Init();
		Paused = false;
	}

	// pause
	if (action != GLFW_RELEASE && GameOver == false) {
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
