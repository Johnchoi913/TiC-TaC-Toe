#include "ttt.h"

int main()
{
    int boardArr[3][3];
    for( int x = 0; x < 3; x++)
    {
        for( int y = 0; y < 3;y++)
        {
            boardArr[x][y] = empty;
        }
    }
    draw(boardArr);
    play(boardArr);
    draw(boardArr);
    return 0;
}