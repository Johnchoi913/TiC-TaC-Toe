#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

/** Draw Method
 * This method draws the board
 * @param boardArr[3][3] takes in the board array to change and print
*/
void draw(int boardArr[DIMENSION][DIMENSION])
{
    for(int row = 0; row < DIMENSION; row++)
    {
        for(int col = 0; col < DIMENSION; col++)
        {
            switch (boardArr[row][col])
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
            
            if(col < DIMENSION - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(row < DIMENSION - 1)
        {
            for(int i = 0; i < DIMENSION * 4; i++)
            {
                printf("_");
            }
        }
        printf("\n");
    }
}

