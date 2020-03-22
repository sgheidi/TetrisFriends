# Tetris Friends

Fully-featured Tetris Friends clone written in OpenGL/C++ using GLFW.

## Screenshots

![Alt text](screenshots/8.png?raw=true "Screenshot 1") &nbsp; &nbsp; &nbsp; ![Alt text](screenshots/9.png?raw=true "Screenshot 2")

## Setting up

First, build GLFW by running ```cmake .``` in the Linux terminal. Play the game by running ```make; ./TetrisFriends```.

## How to play
The left panel displays the held piece and the right 4 panels display the next pieces.
- Special keys
  - 'p': pause
  - 'r': restart
  - 'q' or 'ESC': exit
  - 'Space': 'hard' drops a piece, dropping it instantly
  - 'Shift': Swap current piece with held piece.
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

- Render text to show 'combos', pausing, restarting and other statuses.
- Play sounds to indicate that a player has done a 'combo' (i.e clearing lines consecutively on each piece, T-spins)
- 'Tab': Use an 'item' which temporarily grants a special ability (i.e only long pieces for 10 seconds, clears 7 of the bottom lines, etc)
- Provide different 'map' options with command line arguments
