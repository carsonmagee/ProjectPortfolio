#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <unistd.h>


using namespace std;

//Constant Variables
int const BOARD_SIZE_X=10;
int const BOARD_SIZE_Y=10;
int const NUM_MINES=3;

class board
{
// Access specifier
public:
// Data Members
    bool isWin = false,
         isLose = false,
         firstReveal=false,
         nullByte = false;
    int cursorPosX=0,
        cursorPosY=0;
    time_t startTime=0,
         endTime=0;
    char cursorInput;
};

struct cell
{
// Access specifier
public:
    int value=0;
    bool isCursor=false,
         isRevealed=false,
         isFlag=false,
         isTraveled=false;
};

//Function Prototypes
void printTitle();
void initialize(cell boardArr[][BOARD_SIZE_X], board board); //Creates mines randomly and updates surrounding cells
void moveCursor(cell boardArr[][BOARD_SIZE_X], board board);
void reveal(cell boardArr[][BOARD_SIZE_X], board board, int y, int x);
void print(cell boardArr[][BOARD_SIZE_X], board board);
void reset(cell boardArr[][BOARD_SIZE_X], board board);
void checkWinLose(cell boardArr[][BOARD_SIZE_X], board board, int y, int x);