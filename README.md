# Fruit Tetris

A simple, elegant Tetris implementation written in OpenGL/C++ using GLFW framework.

## Screenshots

![Alt text](screenshots/3.png?raw=true "Screenshot 1") &nbsp; &nbsp; &nbsp; ![Alt text](screenshots/4.png?raw=true "T-Spin!")

## Setting up

Before attempting to play the game, visit [glfw.org](https://www.glfw.org/) and build the library from source using CMake.
Play the game by running ```make && ./FruitTetris``` in the Linux terminal.

## How to play

- Special keys
  - 'p': pause
  - 'r': restart
  - 'q' or 'ESC': exit
  - 'Space' key: 'hard' drops a piece, dropping it instantly
- Movements
  - Up key: rotate piece
  - Left/right keys: horizontal movement
  - Down key: downward acceleration
- **Note: Speed & score increases with each line clear!**

## Other notes

- Entire codebase written from scratch and closely follows Google C++ Style
  - Code is well commented, easy to read and modify
  - Code also broken up into classes and objects for good structure
- All game options are stored in the file ```common.cc``` and can be modified

## Future goals

- Render text to show 'combos', pausing, restarting, staring & losing
- Play sounds to indicate that a player has done a 'combo' (i.e clearing lines consecutively on each piece, T-spins)
- Viewing & ability to swap with a tetronimo that the player has in their queue
  - 'Shift': holds a piece, swapping current piece with held piece (in a queue)
  - 'Next piece' feature: shows next 4 pieces in queue
- 'Tab': Use an 'item' which temporarily grants a special ability (i.e only long pieces for 10 seconds, clears 7 of the bottom lines, etc)
