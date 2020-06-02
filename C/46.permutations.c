/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.96%)
 * Likes:    3598
 * Dislikes: 102
 * Total Accepted:    578.1K
 * Total Submissions: 930.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void backtrack(int *piNums, int iNumSize, int iPos, int *piUsed, int *piPath, 
                int *piReturnSize, int **ppiReturn, int *piReturnCol ){

    if(iPos == iNumSize){
        ppiReturn[*piReturnSize] = (int*)malloc(sizeof(int) * iNumSize);
        memset(ppiReturn[*piReturnSize], 0, sizeof(int) * iNumSize);
        memcpy(ppiReturn[*piReturnSize], piPath, sizeof(int) * iNumSize);
        piReturnCol[*piReturnSize] = iNumSize;
        ++(*piReturnSize);
    }

    for(int i = 0; i < iNumSize; ++i){
        if(!piUsed[i]){
            piUsed[i] = 1;
            piPath[iPos] = piNums[i];
            backtrack(piNums, iNumSize, iPos + 1, piUsed, piPath, piReturnSize, ppiReturn, piReturnCol);
            piUsed[i] = 0;
        }

    }

}



int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int iRetrunSize = 1;
    int **ppiRetrun = NULL;
    int *piReturnCol = NULL;
    int *piUsed = NULL;
    int *piPath = NULL;

    for(int i = 1; i <= numsSize; ++i){
        iRetrunSize *= i;
    }

    ppiRetrun = (int**)malloc(sizeof(int*) * iRetrunSize);
    piReturnCol = (int*)malloc(sizeof(int) * iRetrunSize);
    memset(ppiRetrun, 0, sizeof(int*) * iRetrunSize);
    memset(piReturnCol, 0, sizeof(int) * iRetrunSize);

    piUsed = (int*)malloc(sizeof(int) * numsSize);
    piPath = (int*)malloc(sizeof(int) * numsSize);
    memset(piUsed, 0, sizeof(int) * numsSize);
    memset(piPath, 0, sizeof(int) * numsSize);

    iRetrunSize = 0;

    backtrack(nums, numsSize, 0, piUsed, piPath, &iRetrunSize, ppiRetrun, piReturnCol);

    *returnColumnSizes = piReturnCol;
    *returnSize = iRetrunSize;
    
    return ppiRetrun;
}

int main(){
    int **ppiReturn = NULL;
    int piNums[] = {1,2,3};
    int iNumSize = 3;
    int iReturnSize = 0;
    int *piReturnCol = NULL;

    ppiReturn = permute(piNums, iNumSize, &iReturnSize, &piReturnCol);

    for(int i = 0; i < iReturnSize; ++i){
        for(int j = 0; j < piReturnCol[i]; ++j){
            printf("%d, ", ppiReturn[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < iReturnSize; ++i){
        free(ppiReturn[i]);
    }
    free(ppiReturn);
    free(piReturnCol);

    return 0;
}
// @lc code=end

