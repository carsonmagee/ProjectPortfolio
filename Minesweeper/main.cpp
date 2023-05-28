#include "minesweeper.h"

using namespace std;

int main() {

    printf("\033[30;47m\n");
    //printf("\033[0mdefault colors\n"); //Default Colors

    board board;
    cell boardArr[BOARD_SIZE_Y][BOARD_SIZE_X];

    srand(time(0)); // Use current time as seed for random generator
    printTitle();
    while (1==1)
    {
        reset(boardArr, board);
        initialize(boardArr, board); 
        print(boardArr, board);
        moveCursor(boardArr, board);
    }
    
    return 0;
}

