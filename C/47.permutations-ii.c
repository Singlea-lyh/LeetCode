/*
 * @lc app=leetcode id=47 lang=c
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.65%)
 * Likes:    1788
 * Dislikes: 60
 * Total Accepted:    338.8K
 * Total Submissions: 745.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}
int main(){
    int **ppiReturn = NULL;
    int piNums[] = {1,2,3};
    int iNumSize = 3;
    int iReturnSize = 0;b
    int *piReturnCol = NULL;

    ppiReturn = permuteUnique(piNums, iNumSize, &iReturnSize, &piReturnCol);

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

