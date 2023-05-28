#include "minesweeper.h"

void reset(cell boardArr[][BOARD_SIZE_X], board board)
{
    
    board.isWin = false;
    board.isLose = false;
    board.firstReveal = true;
    board.nullByte = false;
    board.cursorPosX = 0;
    board.cursorPosY = 0;
    board.cursorInput = '\a';

    for (int i=0; i<BOARD_SIZE_Y; i++)
    {
        for (int j=0; j<BOARD_SIZE_X; j++)
        {
            boardArr[i][j].value=0;
            boardArr[i][j].isCursor=false;
            boardArr[i][j].isRevealed=false;
            boardArr[i][j].isTraveled=false;
            boardArr[i][j].isFlag=false;
        }
    }
}

void printTitle()
{
    cout << "\033[2J\033[1;1H";

    cout << " \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "       ___ __ ___   __   ______   ______  \n";
    cout << "      / _   _   /  / /  / __  /  /___ __/ \n";
    cout << "     / / / / / /  / /  / / / /  /____/    \n";
    cout << "    / / /_/ / /  / /  / / / /  /____/     \n";
    cout << "   /_/     /_/  /_/  /_/ /_/  /___ __/    \n";
    cout << "            ________________________________________________    \n";
    cout << "                    __ _ __  __      _  __ ___  __ ___  __ __   __ ___  __ __  \n";
    cout << "                   /          /     /  /     / /     / /     / /     / /     / \n";
    cout << "                  /__ _ __   / _/  /  /____   /____   /___ /  /____   /_ __ /  \n";
    cout << "                         /  /_/ / /  /       /       /       /       /    /    \n";
    cout << "                /__ _ _ /  //   //  /__ __/ /__ __/ /       /__ __/ /     /    \n";

    cout << "\n\n\n\n\n\n\n\n\n                             Program By: Carson Magee\n\n\n\n\n\n";
    cout << "                             Press Enter to Continue . . .\n\n\n\n\n\n\n\n\n\n";
    cin.get();
    cout << "\033[2J\033[1;1H";
}

void initialize(cell boardArr[][BOARD_SIZE_X], board board)
{
    board.startTime = time(0);   // get time now to subtract from the finishing time later

    for (int i=0; i<NUM_MINES; i++)
    {
        int x=rand()%BOARD_SIZE_X;
        int y=rand()%BOARD_SIZE_Y;
        if (boardArr[y][x].value==int('X'))
        {
            i--;
        }
        else
        {
            boardArr[y][x].value=int('X');
        }
        usleep(1000);//needed so system doesn't overload
    }
    int surroundingMinesNum=0;
    for (int i=0; i<BOARD_SIZE_Y; i++)
    {
        for (int j=0; j<BOARD_SIZE_X; j++)
        {
            if(boardArr[i-1][j-1].value==int('X') && i-1!=-1 && j-1!=-1) //Bottom Left
                surroundingMinesNum++;
            if(boardArr[i-1][j].value==int('X') && i-1!=-1) //Bottom Center
                surroundingMinesNum++;
            if(boardArr[i-1][j+1].value==int('X') && i-1!=-1 && j+1!=BOARD_SIZE_X) //Bottom Right
                surroundingMinesNum++;
            if(boardArr[i][j+1].value==int('X') && j+1!=BOARD_SIZE_X) //Right
                surroundingMinesNum++;
            if(boardArr[i+1][j+1].value==int('X') && i+1!=BOARD_SIZE_Y && j+1!=BOARD_SIZE_X) //Top Right
                surroundingMinesNum++;
            if(boardArr[i+1][j].value==int('X') && i+1!=BOARD_SIZE_Y) //Top Center
                surroundingMinesNum++;
            if(boardArr[i+1][j-1].value==int('X') && i+1!=BOARD_SIZE_Y && j-1!=-1) //Top Left
                surroundingMinesNum++;
            if(boardArr[i][j-1].value==int('X') && j-1!=-1) //Left
                surroundingMinesNum++;

            if (boardArr[i][j].value!=int('X')) //if current position is not a mine, insert the # of surrounding mines
                boardArr[i][j].value=surroundingMinesNum;
            surroundingMinesNum=0;
        } 
    }
    boardArr[board.cursorPosY][board.cursorPosX].isCursor=true;
//    printTitle();
}

void moveCursor(cell boardArr[][BOARD_SIZE_X], board board)
{
    boardArr[board.cursorPosY][board.cursorPosX].isCursor = false;
    board.cursorInput=cin.get();
    if (board.cursorInput== 'w' && board.cursorPosY-1!=-1)
        board.cursorPosY--; //Move Cursor Up
    else if (board.cursorInput== 's' && board.cursorPosY+1!=BOARD_SIZE_Y)
        board.cursorPosY++; //Move Cursor Down
    else if (board.cursorInput== 'd' && board.cursorPosX+1!=BOARD_SIZE_X)
        board.cursorPosX++; //Move Cursor Right
    else if (board.cursorInput== 'a' && board.cursorPosX-1!=-1)
        board.cursorPosX--; //Move Cursor Left
    if (board.cursorInput== 'w' || board.cursorInput== 'a' || board.cursorInput== 's' || board.cursorInput== 'd')
        boardArr[board.cursorPosY][board.cursorPosX].isCursor = true;
    else if (board.cursorInput=='r' && boardArr[board.cursorPosY][board.cursorPosX].isFlag==false)
        reveal(boardArr, board, board.cursorPosY, board.cursorPosX);
    else if (board.cursorInput== 'q')
        exit(0);
    else if (board.cursorInput=='f')
    {
        if (boardArr[board.cursorPosY][board.cursorPosX].isFlag==true)
        {
            boardArr[board.cursorPosY][board.cursorPosX].isFlag=false;
            print(boardArr, board);
            print(boardArr, board);
            usleep(500000);
            boardArr[board.cursorPosY][board.cursorPosX].isCursor = true;
            moveCursor(boardArr, board);
        }
            
        boardArr[board.cursorPosY][board.cursorPosX].isFlag=true;
        print(boardArr, board);
        usleep(500000);
        boardArr[board.cursorPosY][board.cursorPosX].isCursor = true;
    }  
    else
        moveCursor(boardArr, board);

    print(boardArr, board);
    moveCursor(boardArr, board);   
}

void reveal(cell boardArr[][BOARD_SIZE_X], board board, int y, int x)
{
    checkWinLose(boardArr, board, y, x);
    boardArr[y][x].isRevealed = true;  
    boardArr[y][x].isCursor = false;    

    if (boardArr[y][x].value==0) //if 0, reveal all other surounding zeros
    {
        //display all 8 surrounding cells
        if (y-1!=-1 && x-1!=-1)
            boardArr[y-1][x-1].isRevealed = true;
        if (y-1!=-1)
            boardArr[y-1][x].isRevealed = true;
        if (y-1!=-1 && x+1!=BOARD_SIZE_X)
            boardArr[y-1][x+1].isRevealed = true;
        if (x+1!=BOARD_SIZE_X)
            boardArr[y][x+1].isRevealed = true;
        if (y+1!=BOARD_SIZE_Y && x+1!=BOARD_SIZE_X)
            boardArr[y+1][x+1].isRevealed = true;
        if (y+1!=BOARD_SIZE_Y)
            boardArr[y+1][x].isRevealed = true;
        if (y+1!=BOARD_SIZE_Y && x-1!=-1)
            boardArr[y+1][x-1].isRevealed = true;
        if (x-1!=-1)
            boardArr[y][x-1].isRevealed = true;

        if (boardArr[y+1][x].value == 0 && y+1!=BOARD_SIZE_Y && boardArr[y+1][x].isTraveled==false)//Top center
        {
            boardArr[y+1][x].isTraveled=true;
            reveal(boardArr, board, y+1, x);
        }
        if (boardArr[y-1][x].value == 0 && y-1!=-1 && boardArr[y-1][x].isTraveled==false)//Bottom center
        {
            boardArr[y-1][x].isTraveled=true;
            reveal(boardArr, board, y-1, x);
        }
        if (boardArr[y][x-1].value == 0 && x-1!=-1 && boardArr[y][x-1].isTraveled==false)//Left
        {
            boardArr[y][x-1].isTraveled=true;
            reveal(boardArr, board, y, x-1);
        }
        if (boardArr[y][x+1].value == 0 && x+1!=BOARD_SIZE_X && boardArr[y][x+1].isTraveled==false)//Right
        {
            boardArr[y][x+1].isTraveled=true;
            reveal(boardArr, board, y, x+1);
        }
        if (boardArr[y-1][x-1].value == 0 && y-1!=-1 && x-1!=-1 && boardArr[y-1][x-1].isTraveled==false)//Bottom left
        {
            boardArr[y-1][x-1].isTraveled=true;
            reveal(boardArr, board, y-1, x-1);
        }
        if (boardArr[y+1][x+1].value == 0 && y+1!=BOARD_SIZE_Y && x+1!=BOARD_SIZE_X && boardArr[y+1][x+1].isTraveled==false)//Top right
        {
            boardArr[y+1][x+1].isTraveled=true;
            reveal(boardArr, board, y+1, x+1);
        }
        if (boardArr[y-1][x+1].value == 0 && y-1!=-1 && x+1!=BOARD_SIZE_X && boardArr[y-1][x+1].isTraveled==false)//Bottom right
        {
            boardArr[y-1][x+1].isTraveled=true;
            reveal(boardArr, board, y-1, x+1);
        }
        if (boardArr[y+1][x-1].value == 0 && y+1!=BOARD_SIZE_Y && x-1!=-1 && boardArr[y+1][x-1].isTraveled==false)//Top left
        {
            boardArr[y+1][x-1].isTraveled=true;
            reveal(boardArr, board, y+1, x-1);
        }
        else 
        {
            boardArr[board.cursorPosY][board.cursorPosX].isCursor=true;
            return;
        }
    }
    
    print(boardArr, board);
    usleep(500000);
    boardArr[y][x].isCursor = true;
    print(boardArr, board);
    checkWinLose(boardArr, board, y, x);
    return;
}

void print(cell boardArr[][BOARD_SIZE_X], board board)
{
    cout << "\033[2J\033[1;1H";
    cout << endl << setw(30) << left << " " << "Mines: " << NUM_MINES << setw(5) << " " << "Level: " << BOARD_SIZE_X << " x " << BOARD_SIZE_Y;
    if(board.isWin==false && board.isLose==false)
    cout << "\n\n\n  'r' = Reveal     //    'f' = Flag     //    'q' = Quit";

    for (int i=0; i < BOARD_SIZE_Y*2+1; i++)
    {
        cout << endl;
        for (int j=0; j < BOARD_SIZE_X+1; j++)
        {
            if (j==0 && i%2==0)
                cout << "-";
            else if (j==0 && i%2!=0)
                cout << "|";
            else if (i%2==0)
                cout << "----";

            else if (boardArr[i/2][j-1].isCursor==true && board.isWin==false && board.isLose==false)
                cout << " # |"; //Display cursor
            else if (boardArr[i/2][j-1].isFlag==true && board.isWin==false && board.isLose==false)
                cout << " % |"; //Display flag
            if ((board.isWin==true || board.isLose==true) && j!=0 && i%2!=0)
            {
                boardArr[i/2][j-1].isRevealed=true;
                boardArr[i/2][j-1].isCursor=false;
                boardArr[i/2][j-1].isFlag=false;
            }
            if (boardArr[i/2][j-1].isRevealed==true && boardArr[i/2][j-1].isCursor==false && boardArr[i/2][j-1].isFlag==false && j!=0 && i%2!=0)
            {
                if (boardArr[i/2][j-1].value==0)  //if the cell is zero, print a blank cell
                    cout << "   |";
                else if (boardArr[i/2][j-1].value==int('X'))
                    cout << " " << char(boardArr[i/2][j-1].value) << " |"; //Display bomb
                else
                    cout << " " << boardArr[i/2][j-1].value << " |"; //Display number
            }
            else if (boardArr[i/2][j-1].isRevealed==false && boardArr[i/2][j-1].isCursor==false && boardArr[i/2][j-1].isFlag==false && board.isWin==false && board.isLose==false && j!=0 && i%2!=0)
                cout << " · |";
        }
    }
    cout << endl;
    if(board.isWin==true || board.isLose==true)
    {
        if (board.isWin==true)
        {
            board.endTime = time(0);
            cout << "You win!\n";
        }
        else if (board.isLose==true)
        {
            board.endTime = time(0);
            cout << "You lost.\n";
        }
        cout << "Your Time: " << (board.endTime - board.startTime)/60 << endl << endl; //total time taken from start to finish
        cout << "Play again (y or n)? : ";
        
        char playAgain;
        playAgain=cin.get();
        playAgain=cin.get();
        if (playAgain=='y')
        {
            board.endTime = 0;
            board.startTime = 0;
            board.isWin = false;
            board.isLose = false;
            board.firstReveal = true;
            board.nullByte = false;
            board.cursorPosX = 0;
            board.cursorPosY = 0;
            board.cursorInput = '\a';

            for (int i=0; i<BOARD_SIZE_Y; i++)
            {
                for (int j=0; j<BOARD_SIZE_X; j++)
                {
                    boardArr[i][j].value=0;
                    boardArr[i][j].isCursor=false;
                    boardArr[i][j].isRevealed=false;
                    boardArr[i][j].isTraveled=false;
                    boardArr[i][j].isFlag=false;
                }
            }
            initialize(boardArr, board); 
            print(boardArr, board);
            moveCursor(boardArr, board);
        }
        else if (playAgain=='n')
            exit(0);
        else 
            exit(0);
    }
    if(board.isWin==false && board.isLose==false)
        cout << " Use WASD keys to move cursor: ";
    return;
}

void checkWinLose(cell boardArr[][BOARD_SIZE_X], board board, int y, int x)
{
    int revealCount=0;
    
    for (int i=0; i<BOARD_SIZE_Y; i++)
    {
        for (int j=0; j<BOARD_SIZE_X; j++)
        {
            if (boardArr[i][j].isRevealed==true)
                revealCount++;
        }
    }
    if (revealCount==BOARD_SIZE_Y*BOARD_SIZE_X-NUM_MINES)
    {
        board.isWin=true;
    }
    if (boardArr[y][x].value==int('X'))
        board.isLose=true;

    if (revealCount==1 && boardArr[y][x].value!=0 && board.isWin==false && board.isLose==false)
    {
        reset(boardArr, board);
        initialize(boardArr, board);
        revealCount=0;
        reveal(boardArr, board, y, x);
    }

    if (board.isWin==true || board.isLose==true)
        print(boardArr, board);

    return;
}