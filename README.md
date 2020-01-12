# Fruit Tetris

A simple, elegant Tetris implementation written in OpenGL/C++ using GLFW framework.

## Setting up

Before attempting to play the game, visit [glfw.org](https://www.glfw.org/) and build the library from source using CMake.

Play the game by running ``` make && ./FruitTetris ``` in the Linux terminal.

## How to play

- 'p': pause

- 'q' or 'ESC': exit

- Up key: rotate piece

- Left/right keys: horizontal movement

- Down key: downward acceleration

- Speed & score increases with each line clear!

## Screenshots

## Other notes

- Code is well commented, easy to read and modify

- Code broken up into classes and objects for good structure

- All game options are stored in the file ```common.cc``` and can be modified

## Future goals

- 'Space': 'hard' drops a piece, stacking it directly on board

- 'r': restart game

- 'Shift': holds a piece, swapping the current piece the held piece

- 'Next piece' feature shows next 4 pieces
