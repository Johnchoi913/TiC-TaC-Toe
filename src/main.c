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


int handleGamemodeInput(struct board board)
{
    char* gameModeInput = malloc(sizeof(char));
    printf("Select Game Mode\n");
    printf("1. Local Single Player\n");
    printf("2. Local AI\n");
    //Allows to make sure buffer is always fine and atoi should return 0 if not an int
    scanf("%1s",gameModeInput);
    int gameMode = atoi(gameModeInput);
    free(gameModeInput);
    switch(gameMode)
    {
        case 1:
            playLocal(board);
            return 1;
        case 2:
            playLocalAI(board);
            return 1;
        default:
            return -1;
    }
}

int main()
{
    int dimension = 0;
    printf("Enter the size of the board: \n");
    scanf("%d",&dimension);
    struct board board = makeBoard(dimension);
    while(handleGamemodeInput(board) == -1)
    {
        printf("Invalid Input\n");
    }
    draw(board);
    freeBoard(&board);
    
    return 0;
}