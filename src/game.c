#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

/** Game Over Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to to check
*/
int checkGameOver(char player, struct board board)
{
    player = player == 0 ? X : O;
    //Responsible for checking the horizontal and vertical vicories
    for(int x = 0; x < board.dimension; x++)
    {
        for(int y = 0; y < board.dimension; y++)
        {
            if(board.boardArr[x][y] != player)
            {
                break;
            }
            if(y == board.dimension - 1)
            {
                return TRUE;
            }
        }
        for(int y = 0; y < board.dimension; y++)
        {
            if(board.boardArr[y][x] != player)
            {
                break;
            }
            if(y == board.dimension - 1)
            {
                return TRUE;
            }
        }
    }
    //Checking the diagonal victories
    for(int i = 0; i < board.dimension; i++)
    {
        if(board.boardArr[i][i] != player)
        {
            break;
        }
        if(i == board.dimension - 1)
        {
            return TRUE;
        }
    }
    for(int i = 0; i < board.dimension; i++)
    {
        if(board.boardArr[i][board.dimension-i-1] != player)
        {
            break;
        }
        if(i == board.dimension - 1)
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
int handleInput(int row_in, int col_in, struct board board)
{
    //Out of Bounds
    if(row_in < 0 || row_in > board.dimension - 1 || col_in < 0 || col_in > board.dimension - 1)
    {
        return FALSE;
    }
    //Already taken
    if(board.boardArr[row_in][col_in] != empty)
    {
        return FALSE;
    }
    return TRUE;
}

/** Play Game Locally no AI Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to pass into the other two methods
*/
void playLocal(struct board board)
{
    draw(board);
    printf("Welcome to my TicTacToe game\n");
    printf("Make a move in the format of row col (Starts at 0)\n");
    int row_in,col_in;
    char player = 0;
    int count = 0;
    while(count < board.dimension * board.dimension)
    {        
        scanf("%d %d",&row_in,&col_in);
        if(!handleInput(row_in,col_in,board))
        {
            printf("Invalid input\n");
        }
        else
        {
            board.boardArr[row_in][col_in] = player == 0 ? X : O;
           
            if(checkGameOver(player,board))
            {
                printf("Player %c wins\n",player == 0 ? 'X' : 'O');
                return;
            }
            player = !player;
            count++;
        }
        draw(board);

    }
    printf("Tie\n");
    
}

/** Play Game Locally AI Method
 * This method checks if the game is over
 * @param boardArr[3][3] takes in the board array to pass into the other two methods
*/
void playLocalAI(struct board board)
{
    draw(board);
    printf("Welcome to my TicTacToe game\n");
    printf("Make a move in the format of row col (Starts at 0)\n");
    int row_in,col_in;
    char player = 0;
    int count = 0;
    while(count < board.dimension * board.dimension)
    {        
        if(player == 0)
        {
            struct moveValue moveValue = minimax(board,player,1);
            printf("best move is %d %d\n",moveValue.row,moveValue.col);
            printf("best move val is %d\n",moveValue.expVal);
        }
        scanf("%d %d",&row_in,&col_in);
        if(!handleInput(row_in,col_in,board))
        {
            printf("Invalid input\n");
        }
        else
        {
            board.boardArr[row_in][col_in] = player == 0 ? X : O;
           
            if(checkGameOver(player,board))
            {
                printf("Player %c wins\n",player == 0 ? 'X' : 'O');
                return;
            }
            player = !player;
            count++;
        }
        draw(board);

    }
    printf("Tie\n");
    
}