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

// struct moveValue getBestMove(struct board board, char player, int row, int col)
// {
//     struct moveValue moveValue;
//     moveValue.expVal = 0;
//     if(checkGameOver(player == X ? O : X,board))
//     {
//         moveValue.row = row;
//         moveValue.col = col;
//         moveValue.expVal = player == X ? -100 : 100;
//         return moveValue;
//     }


//     int emptyCount = getEmptyCount(board);
//     struct moveValue bestMove[emptyCount];

//     int moveIndex = 0;

//     for(int x = 0; x < board.dimension; x++)
//     {
//         for(int y = 0; y < board.dimension; y++)
//         {
//             if(board.boardArr[x][y] == empty)
//             {
//                 struct board newBoard;
//                 newBoard = deepCopyBoard(board);
//                 newBoard.boardArr[x][y] = player;
//                 struct moveValue newMoveValue = getBestMove(newBoard, player == X ? O : X, x, y);
//                 newMoveValue.col = y;
//                 newMoveValue.row = x;
//                 freeBoard(&newBoard);
//                 bestMove[moveIndex] = newMoveValue;
//                 moveIndex++;
//             }
//         }
//     }
//     for(int i = 0; i < emptyCount; i++)
//     {
//         if(player == X)
//         {
//             if(bestMove[i].expVal > moveValue.expVal)
//             {
//                 moveValue = bestMove[i];
//             }
//         }
//         else
//         {
//             if(bestMove[i].expVal < moveValue.expVal)
//             {
//                 moveValue = bestMove[i];
//             }
//         }
//     }
//     return moveValue;
// }

struct moveValue minimax(struct board board, char player)
{
    int emptyCount = getEmptyCount(board);
    struct moveValue bestMove[emptyCount];
    for(int i = 0; i < emptyCount; i++)
    {
        bestMove[i].expVal = 0;
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
                    moveValue.expVal = player == 0 ? 1 : -1;
                    freeBoard(&newBoard);
                    return moveValue;
                }
                //struct moveValue newMoveValue = getBestMove(newBoard, player == X ? O : X, x, y);
                struct moveValue newMoveValue = minimax(newBoard, !player);
                newMoveValue.col = y;
                newMoveValue.row = x;
                freeBoard(&newBoard);
                bestMove[moveIndex] = newMoveValue;
                moveIndex++;
            }
        }
    }
    if(emptyCount == 1)
    {
        return bestMove[0];
    }
    struct moveValue moveValue;
    moveValue.expVal = player == 0 ? -1 : 1;
    for(int i = 0; i < emptyCount; i++)
    {
        if(bestMove[i].expVal == 0)
        {
            puts("TIE FOUND");
        }
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