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

void solveSudoku(char** board, int boardSize, int* boardColSize){

}


int main(){
    char pacInput[9][9] ={
        {5,3,'.','.',7,'.','.','.','.'},
        {6,'.','.',1,9,5,'.','.','.'},
        {'.',9,8,'.','.','.','.',6,'.'},
        {8,'.','.','.',6,'.','.','.',3},
        {4,'.','.',8,'.',3,'.','.',1},
        {7,'.','.','.',2,'.','.','.',6},
        {'.',6,'.','.','.','.',2,8,'.'},
        {'.','.','.',4,1,9,'.','.',5},
        {'.','.','.','.',8,'.','.',7,9}
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

    printf("%d\n", bIsReturn);

    return 0;
}
// @lc code=end

