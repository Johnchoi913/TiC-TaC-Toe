#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

/** Game Over Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to to check
*/
int checkGameOver(char player, int boardArr[3][3])
{
    player = player == 0 ? O : X;
    //Responsible for checking the horizontal and vertical vicories
    for(int i = 0; i < 3; i++)
    {
        if(boardArr[i][0] == player && boardArr[i][1] == player && boardArr[i][2] == player)
        {
            return TRUE;
        }
        if(boardArr[0][i] == player && boardArr[1][i] == player && boardArr[2][i] == player)
        {
            return TRUE;
        }
    }
    //Checking the diagonal victories
    if(boardArr[0][0] == player && boardArr[1][1] == player && boardArr[2][2] == player)
    {
        return TRUE;
    }
    if(boardArr[0][2] == player && boardArr[1][1] == player && boardArr[2][0] == player)
    {
        return TRUE;
    }
    return FALSE;
}

/** Input Method
 * This method validates the input
 * @param boardArr[3][3] takes in the board array to validate
 * @param row_in takes in the row input
 * @param col_in takes in the column input
*/
int handleInput(int row_in, int col_in, int boardArr[3][3])
{
    //Out of Bounds
    if(row_in < 0 || row_in > 2 || col_in < 0 || col_in > 2)
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
void play(int boardArr[3][3])
{
    printf("Welcome to my TicTacToe game\n");
    printf("Make a move in the format of row col (Starts at 0)\n");
    int row_in,col_in;
    char player = 0;
    int count = 0;
    while(count < 9)
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
                break;
            }
            count++;
        }
        draw(boardArr);
    }
    printf("Tie\n");
    
}

