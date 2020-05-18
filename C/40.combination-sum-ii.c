/*
 * @lc app=leetcode id=40 lang=c
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (46.10%)
 * Likes:    1557
 * Dislikes: 59
 * Total Accepted:    308.8K
 * Total Submissions: 660.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
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

#define MAX_LEN 256


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

}

int main(){
    int aiCandidates[] = {2,3,6,7};
    int iCandidatesSize = 4;
    int iTarget = 6;
    int iReturnSize = 0;
    int* ppReturnColumnsSize = NULL;
    int** ppReturn = NULL;

    ppReturn = combinationSum2(aiCandidates, iCandidatesSize, iTarget, &iReturnSize, &ppReturnColumnsSize);

    printf("[\n");
    for(int i = 0; i < iReturnSize; ++i){
        printf("[");        
        for(int j = 0; j < (ppReturnColumnsSize)[i]; ++j){
            printf("%d, ", ppReturn[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");

    for(int i = 0; i < iReturnSize; ++i){
        free(ppReturn[i]);
    }
    free(ppReturn);

    return 0;
}

// @lc code=end

