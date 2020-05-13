/*
 * @lc app=leetcode id=37 lang=c
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (41.39%)
 * Likes:    1561
 * Dislikes: 89
 * Total Accepted:    175.5K
 * Total Submissions: 417.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

#define N 9

void placeNextNum(char ppcBoard[][9], int iRow, int iCol);
// void placeNextNum(char** ppcBoard, int iRow, int iCol);

char aiRows[N][N + 1] = {0};
char aiCols[N][N + 1] = {0};
char aiBoxs[N][N + 1] = {0};

bool bIsSolve = false;

// void placeNum(char** ppcBoard, int iNum, int iRow, int iCol){
//     int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

//     aiRows[iRow][iNum]++;
//     aiCols[iCol][iNum]++;
//     aiBoxs[iBoxIndex][iNum]++;
//     ppcBoard[iRow][iCol] = (char)iNum;

//     return;
// }

// bool couldPlace(int iNum, int iRow, int iCol){
//     int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

//     if(aiRows[iRow][iNum] || aiCols[iCol][iNum] || aiBoxs[iBoxIndex][iNum]){
//         return false;
//     }
//     else{
//         return true;
//     }
// }

// void removeNum(char** ppcBoard, int iNum, int iRow, int iCol){
//     int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

//     aiRows[iRow][iNum]--;
//     aiCols[iCol][iNum]--;
//     aiBoxs[iBoxIndex][iNum]--;
//     ppcBoard[iRow][iCol] = '.';

//     return;
// }

// void backtrace(char** ppcBoard, int iRow, int iCol){

//     if(ppcBoard[iRow][iCol] == '.'){
//         for(int i = 1; i < 10; ++i){           
//             int iNum = i;
//             if(couldPlace(iNum, iRow, iCol)){
//                 placeNum(ppcBoard, iNum, iRow, iCol);
//                 placeNextNum(ppcBoard, iRow, iCol);
//                 if(!bIsSolve) removeNum(ppcBoard, iNum, iRow, iCol);
//             }
//         }
//     }
//     else{
//         placeNextNum(ppcBoard, iRow, iCol);
//     }
    
//     return;
// }

// void placeNextNum(char** ppcBoard, int iRow, int iCol){
//     if(iRow == N - 1 && iCol == N - 1){
//         bIsSolve = true;
//     }
//     else{
//         if(iCol == N -1){
//             backtrace(ppcBoard, iRow + 1, 0);            
//         }
//         else{
//             backtrace(ppcBoard, iRow, iCol + 1);
//         }
//     }
//     return;
// }


// void solveSudoku(char** board, int boardSize, int* boardColSize){
//     for(int i = 0; i < N; ++i){
//         for(int j = 0; j < N; ++j){
//             char cNum = board[i][j];
//             if(cNum != '.'){
//                 int iNum = board[i][j] - '0';
//                 placeNum(board, iNum, i, j);
//             }
//         }
//     }
//     backtrace(board, 0, 0);

//     return;
// }


void placeNum(char ppcBoard[][9], int iNum, int iRow, int iCol){
    int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

    aiRows[iRow][iNum] = 1;
    aiCols[iCol][iNum] = 1;
    aiBoxs[iBoxIndex][iNum] = 1;
    ppcBoard[iRow][iCol] = (char)(iNum + '0');

    return;
}

bool couldPlace(int iNum, int iRow, int iCol){
    int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

    if(aiRows[iRow][iNum] || aiCols[iCol][iNum] || aiBoxs[iBoxIndex][iNum]){
        return false;
    }
    else{
        return true;
    }
}

void removeNum(char ppcBoard[][9], int iNum, int iRow, int iCol){
    int iBoxIndex = (iRow / 3) * 3 + (iCol / 3);

    aiRows[iRow][iNum] = 0;
    aiCols[iCol][iNum] = 0;
    aiBoxs[iBoxIndex][iNum] = 0;
    ppcBoard[iRow][iCol] = '.';

    return;
}

void backtrace(char ppcBoard[][9], int iRow, int iCol){

    if(ppcBoard[iRow][iCol] == '.'){
        for(int i = 1; i < 10; ++i){           
            int iNum = i;
            if(couldPlace(iNum, iRow, iCol)){
                placeNum(ppcBoard, iNum, iRow, iCol);
                placeNextNum(ppcBoard, iRow, iCol);

                if(!bIsSolve) removeNum(ppcBoard, iNum, iRow, iCol);
            }
        }
    }
    else{
        placeNextNum(ppcBoard, iRow, iCol);
    }
    
    return;
}

void placeNextNum(char ppcBoard[][9], int iRow, int iCol){
    if(iRow == N - 1 && iCol == N - 1){
        bIsSolve = true;
    }
    else{
        if(iCol == N -1){
            backtrace(ppcBoard, iRow + 1, 0);            
        }
        else{
            backtrace(ppcBoard, iRow, iCol + 1);
        }
    }
    return;
}


void solveSudoku(char board[][9], int boardSize, int* boardColSize){

    if(boardSize < 9){
        return;
    }
    
    
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardColSize[i]; ++j){
            char cNum = board[i][j];
            if(cNum != '.'){
                int iNum = cNum;
                placeNum(board, iNum, i, j);
            }
        }
    }
    backtrace(board, 0, 0);

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            printf("%c, ", board[i][j]);
        }
        printf("\n");
    }

    printf("*****************************\n");

    

    return;
}



int main(){
    // char pacInput[9][9] ={
    //     {5,3,'.','.',7,'.','.','.','.'},
    //     {6,'.','.',1,9,5,'.','.','.'},
    //     {'.',9,8,'.','.','.','.',6,'.'},
    //     {8,'.','.','.',6,'.','.','.',3},
    //     {4,'.','.',8,'.',3,'.','.',1},
    //     {7,'.','.','.',2,'.','.','.',6},
    //     {'.',6,'.','.','.','.',2,8,'.'},
    //     {'.','.','.',4,1,9,'.','.',5},
    //     {'.','.','.','.',8,'.','.',7,9}
    // } ; 
    char pacInput[9][9] ={
            {'.','.',9,7,4,8,'.','.','.'},
            {7,'.','.','.','.','.','.','.','.'},
            {'.',2,'.',1,'.',9,'.','.','.'},
            {'.','.',7,'.','.','.',2,4,'.'},
            {'.',6,4,'.',1,'.',5,9,'.'},
            {'.',9,8,'.','.','.',3,'.','.'},
            {'.','.','.',8,'.',3,'.',2,'.'},
            {'.','.','.','.','.','.','.','.',6},
            {'.','.','.',2,8,7,5,'.','.'}
        } ;

    // char **ppBoard = (char**)pacInput;
    int iBoardSize = 9;
    int aiBoardColSize[] = {9,9,9,9,9,9,9,9,9}; 
    bool bIsReturn = false;

    // for(int i = 0; i < 9; ++i){
    //     for(int j = 0; j < 9; ++j){
    //         printf("%c, ", pacInput[i][j]);
    //     }
    //     printf("\n");

    // }

    solveSudoku(pacInput, iBoardSize, aiBoardColSize);

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            printf("%c, ", pacInput[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// @lc code=end

