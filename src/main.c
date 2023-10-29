#include "ttt.h"
#include <stdio.h>
#include <stdlib.h>


struct board makeBoard(int dimension)
{
    struct board board;
    board.dimension = dimension;
    board.boardArr = calloc(sizeof(int*),dimension);
    for(int i = 0; i < dimension; i++)
    {
        board.boardArr[i] = calloc(sizeof(int),dimension);
    }
    return board;
}

void freeBoard(struct board* board)
{
    if(board == NULL)
    {
        return;
    }
    for(int i = 0; i < board->dimension; i++)
    {
        free(board->boardArr[i]);
    }
    free(board->boardArr);
}

int main()
{
    int dimension = 0;
    printf("Enter the size of the board: ");
    scanf("%d",&dimension);
    struct board board = makeBoard(dimension);
    draw(board);
    play(board);
    draw(board);
    freeBoard(&board);
    return 0;
}