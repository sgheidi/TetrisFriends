# Tetris Friends

Tetris Friends clone written in OpenGL/C++ using GLFW.

## Screenshots

![Alt text](screenshots/8.png?raw=true "Screenshot 1") &nbsp; &nbsp; &nbsp; ![Alt text](screenshots/6.png?raw=true "T-Spin!")

## Setting up

Before attempting to play the game, visit [glfw.org](https://www.glfw.org/) and build the library from source using CMake.
Play the game by running ```make; ./TetrisFriends``` in the Linux terminal.

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

- Render text to show 'combos', pausing, restarting, starting, losing and # of lines cleared
- Play sounds to indicate that a player has done a 'combo' (i.e clearing lines consecutively on each piece, T-spins)
- Viewing next pieces & swapping current tetronimo with 'held' piece
  - 'Next piece' feature: shows next 4 pieces in queue
  - 'Shift': holds a piece, swapping current piece with held piece (in a queue)
- 'Tab': Use an 'item' which temporarily grants a special ability (i.e only long pieces for 10 seconds, clears 7 of the bottom lines, etc)
- Provide different 'map' options with command line arguments
