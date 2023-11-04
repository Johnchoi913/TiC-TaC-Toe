#include "ttt.h"
#include <stdio.h>
#include <stdlib.h>

struct board deepCopyBoard(struct board board)
{
    struct board newBoard;
    newBoard.dimension = board.dimension;
    newBoard.boardArr = calloc(sizeof(int*),board.dimension);
    for(int i = 0; i < board.dimension; i++)
    {
        newBoard.boardArr[i] = calloc(sizeof(int),board.dimension);
    }
    for(int x = 0; x < board.dimension; x++)
    {
        for(int y = 0; y < board.dimension; y++)
        {
            newBoard.boardArr[x][y] = board.boardArr[x][y];
        }
    }
    return newBoard;
}

int getEmptyCount(struct board board)
{
    int emptyCount = 0;
    for(int x = 0; x < board.dimension; x++)
    {
        for(int y = 0; y < board.dimension; y++)
        {
            if(board.boardArr[x][y] == empty)
            {
                emptyCount++;
            }
        }
    }
    return emptyCount;
}

struct moveValue minimax(struct board board, char player, int currDepth)
{
    int emptyCount = getEmptyCount(board);
    struct moveValue bestMove[emptyCount];
    for(int i = 0; i < emptyCount; i++)
    {
        bestMove[i].expVal = 0;
        bestMove[i].row = -1;
        bestMove[i].col = -1;
    }
    int moveIndex = 0;
    for(int x = 0; x < board.dimension; x++)
    {
        for(int y = 0; y < board.dimension; y++)
        {
            if(board.boardArr[x][y] == empty)
            {
                struct board newBoard = deepCopyBoard(board);
                newBoard.boardArr[x][y] = player == 0 ? X : O;
                if(checkGameOver(player,newBoard))
                {
                    struct moveValue moveValue;
                    moveValue.row = x;
                    moveValue.col = y;
                    moveValue.expVal = player == 0 ? board.dimension * board.dimension - currDepth : -1 * (board.dimension * board.dimension - currDepth);
                    freeBoard(&newBoard);
                    return moveValue;
                }
                struct moveValue newMoveValue;
                newMoveValue.expVal = 0;
                newMoveValue.col = y;
                newMoveValue.row = x;
                struct moveValue temp;
                temp = minimax(newBoard, !player, currDepth + 1);
                newMoveValue.expVal = temp.expVal;
                freeBoard(&newBoard);
                bestMove[moveIndex] = newMoveValue;
                moveIndex++;
            }
        }
    }
    if(emptyCount == 0)
    {
        struct moveValue temp;
        temp.row = -1;
        temp.col = -1;
        temp.expVal = 0;
        return temp;
    }
    struct moveValue moveValue;
    moveValue.expVal = player == 0 ? -(board.dimension * board.dimension): board.dimension * board.dimension;
    for(int i = 0; i < emptyCount; i++)
    {
        if(player == 0)
        {
            if(bestMove[i].expVal > moveValue.expVal)
            {
                moveValue = bestMove[i];
            }
        }
        else
        {
            if(bestMove[i].expVal < moveValue.expVal)
            {
                moveValue = bestMove[i];
            }
        }
    }
    return moveValue;
}