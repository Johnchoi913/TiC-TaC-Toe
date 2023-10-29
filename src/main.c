#include "ttt.h"
#include <stdio.h>

int main()
{
    int size = 0;
    printf("Enter the size of the board: ");
    scanf("%d",&size);
    #undef DIMENSION
    #define DIMENSION size
    int boardArr[DIMENSION][DIMENSION];
    for( int x = 0; x < DIMENSION; x++)
    {
        for( int y = 0; y < DIMENSION;y++)
        {
            boardArr[x][y] = empty;
        }
    }
    draw(boardArr);
    play(boardArr);
    draw(boardArr);
    return 0;
}