#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

/** Draw Method
 * This method draws the board
 * @param boardArr[3][3] takes in the board array to change and print
*/
void draw(struct board board)
{
    for(int row = 0; row < board.dimension; row++)
    {
        for(int col = 0; col < board.dimension; col++)
        {
            switch (board.boardArr[row][col])
            {
            case empty:
                printf("   ");
                break;
            case X:
                printf(" X ");
                break;
            case O:
                printf(" O ");
                break;
            default:
                break;
            }
            
            if(col < board.dimension - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(row < board.dimension - 1)
        {
            for(int i = 0; i < board.dimension * 4; i++)
            {
                printf("_");
            }
        }
        printf("\n");
    }
}

