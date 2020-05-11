/*
 * @lc app=leetcode id=36 lang=c
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (47.12%)
 * Likes:    1447
 * Dislikes: 428
 * Total Accepted:    339.4K
 * Total Submissions: 712.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
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

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int iRow[9][10] = {0};
    int iCol[9][10] = {0};
    int iBox[9][10] = {0};

    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j  < boardColSize[i]; ++j){

            if(board[i][j] == '.') continue;

            int iNums = board[i][j] - '0';
            if(iRow[i][iNums]) return false;
            if(iCol[j][iNums]) return false;
            if(iBox[j / 3 + (i / 3) * 3][iNums]) return false;

            iRow[i][iNums] = 1;
            iCol[j][iNums] = 1;
            iBox[j / 3 + (i / 3) * 3][iNums] = 1;
        }
    }

    return true;
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
    char **ppBoard = (char**)pacInput;
    int iBoardSize = 9;
    int aiBoardColSize[] = {9,9,9,9,9,9,9,9,9}; 
    bool bIsReturn = false;

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            printf("%c, ", pacInput[i][j]);
        }
        printf("\n");

    }

    bIsReturn = isValidSudoku(ppBoard, iBoardSize, aiBoardColSize);

    printf("%d\n", bIsReturn);

    return 0;
}

// @lc code=end

