#include <stdio.h>
#include <stdlib.h>

void play()
{
    print("Welcome to my TicTacToe game\n");
    print("Make a move in the format of row col (Starts at 0)\n");
    int row_in,col_in;
    while(1)
    {
        scanf("%d %d",&row_in,&col_in);
        if(row_in == 0 || row_in == 1 || row_in == 2)
        {
            if(col_in == 0 || col_in == 1 || col_in == 2)
            {
                break;
            }
        }
        print("Invalid input");
    }
    
}