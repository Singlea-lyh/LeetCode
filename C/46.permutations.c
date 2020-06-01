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


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}

int main(){
    int **ppiReturn = NULL;
    int piNums[] = {};
    int iNumSize = 0;
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

