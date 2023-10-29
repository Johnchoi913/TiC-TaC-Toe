#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

/** Game Over Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to to check
*/
int checkGameOver(char player, int boardArr[DIMENSION][DIMENSION])
{
    player = player == 0 ? O : X;
    //Responsible for checking the horizontal and vertical vicories
    for(int x = 0; x < DIMENSION; x++)
    {
        for(int y = 0; y < DIMENSION; y++)
        {
            if(boardArr[x][y] != player)
            {
                break;
            }
            if(y == DIMENSION - 1)
            {
                return TRUE;
            }
        }
        for(int y = 0; y < DIMENSION; y++)
        {
            if(boardArr[y][x] != player)
            {
                break;
            }
            if(y == DIMENSION - 1)
            {
                return TRUE;
            }
        }
    }
    //Checking the diagonal victories
    for(int i = 0; i < DIMENSION; i++)
    {
        if(boardArr[i][i] != player)
        {
            break;
        }
        if(i == DIMENSION - 1)
        {
            return TRUE;
        }
    }
    for(int i = 0; i < DIMENSION; i++)
    {
        if(boardArr[i][DIMENSION-i] != player)
        {
            break;
        }
        if(i == DIMENSION - 1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/** Input Method
 * This method validates the input
 * @param boardArr[3][3] takes in the board array to validate
 * @param row_in takes in the row input
 * @param col_in takes in the column input
*/
int handleInput(int row_in, int col_in, int boardArr[DIMENSION][DIMENSION])
{
    //Out of Bounds
    if(row_in < 0 || row_in > DIMENSION - 1 || col_in < 0 || col_in > DIMENSION - 1)
    {
        return FALSE;
    }
    //Already taken
    if(boardArr[row_in][col_in] != empty)
    {
        return FALSE;
    }
    return TRUE;
}

/** Game Over Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to pass into the other two methods
*/
void play(int boardArr[DIMENSION][DIMENSION])
{
    printf("Welcome to my TicTacToe game\n");
    printf("Make a move in the format of row col (Starts at 0)\n");
    int row_in,col_in;
    char player = 0;
    int count = 0;
    while(count < DIMENSION * DIMENSION)
    {
        scanf("%d %d",&row_in,&col_in);
        if(!handleInput(row_in,col_in,boardArr))
        {
            printf("Invalid input\n");
        }
        else
        {
            boardArr[row_in][col_in] = player == 0 ? X : O;
            player = !player;
            if(checkGameOver(player,boardArr))
            {
                printf("Player %c wins\n",player == 0 ? 'O' : 'X');
                return;
            }
            count++;
        }
        draw(boardArr);
    }
    printf("Tie\n");
    
}

