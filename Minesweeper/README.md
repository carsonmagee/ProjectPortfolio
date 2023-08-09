# Minesweeper
This project is a fully functional version of the original game, Minesweeper originally created by Microsoft. The main purpose of this project is to demonstrate implementation of basic back end and front end game development using scrictly native C++ programming in the command line.

## Motivation
The motivation behind this project was to quickly produce a functioning game, using the limitations of a non-GUI and native C++ code.

## Screenshots
<img src="https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/580126a3-379b-4742-9b8f-f77913b689da" width="200" />

## Features
Feel free to change the difficulty of the game by increasing the plot size and bomb amounts. This can be done by changing the constant values within minesweeper.h file.
```
//Constant Variables
int const BOARD_SIZE_X=10;
int const BOARD_SIZE_Y=10;
int const NUM_MINES=3;
```

This project is a skeleton of the original minesweeper game, including all of the original features. This means the code is highly manageable and can easily have a more robust Graphical User Interface added on, as well as more in game capabilities.

## Installation
Windows:
Follow this tutorial to setup a C++ environment: https://code.visualstudio.com/docs/cpp/config-mingw
Then continue with the following Linux code.

Ubuntu and Linux
```
g++ *.cpp -o minesweeper
./minesweeper
```

## Tests
Follow the on screen controls and have fun!
