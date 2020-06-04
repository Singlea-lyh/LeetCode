/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (54.10%)
 * Likes:    2826
 * Dislikes: 219
 * Total Accepted:    390.9K
 * Total Submissions: 706.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0 || matrixSize == 1){
        return;
    }

    for(int i = 0; i < matrixSize; ++i){
        for(int j = i; j < matrixSize; ++j){
            int iTemp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = iTemp;
        }
    }

    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize / 2; ++j){
            int iTemp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize-j-1] = iTemp;
        }
    }

    return;
}

int main(){
    int **ppMatrix = NULL;
    int iMatrixSize = 3;
    int *piMatrixColSize = NULL;

    ppMatrix = (int**)malloc(sizeof(int*) * iMatrixSize);
    piMatrixColSize = (int*)malloc(sizeof(int) * iMatrixSize);
    memset(ppMatrix, 0, sizeof(int*) * iMatrixSize);
    memset(piMatrixColSize, 0, sizeof(int*) * iMatrixSize);
    for(int i = 0; i < iMatrixSize; ++i){
        piMatrixColSize[i] = iMatrixSize;
        ppMatrix[i] = (int*)malloc(sizeof(int) * iMatrixSize);
        memset(ppMatrix[i], 0, sizeof(int*) * iMatrixSize);
    }

    ppMatrix[0][0] = 1;
    ppMatrix[0][1] = 2;
    ppMatrix[0][2] = 3;
    ppMatrix[1][0] = 4;
    ppMatrix[1][1] = 5;
    ppMatrix[1][2] = 6;
    ppMatrix[2][0] = 7;
    ppMatrix[2][1] = 8;
    ppMatrix[2][2] = 9;

    rotate(ppMatrix, iMatrixSize, piMatrixColSize);

    for(int i = 0; i < iMatrixSize; ++i){
        for(int j = 0; j < iMatrixSize; ++j){
            printf("%d, ", ppMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


// @lc code=end

