#include <stdio.h>
#include <stdlib.h>

enum tile{empty,X,O};

void draw(int boardArr[3][3])
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
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
            
            if(col < 2)
            {
                printf("|");
            }
        }
        if(row < 2)
        {
            for(int i = 0; i < 12; i++)
            {
                printf("_");
            }
        }
    }
}

