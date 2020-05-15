/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    3394
 * Dislikes: 105
 * Total Accepted:    505.3K
 * Total Submissions: 926.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    


}

int main(){
    int aiCandidates[] = {};
    int iCandidatesSize = 0;
    int iTarget = 0;
    int iReturnSize = 0;
    int** ppReturnColumnsSize = NULL;
    int** ppReturn = NULL;

    ppReturn = combinationSum(aiCandidates, iCandidatesSize, iTarget, &iReturnSize, ppReturnColumnsSize);

    printf("[\n");
    for(int i = 0; i < iReturnSize; ++i){
        printf("[");        
        for(int j = 0; j < ppReturnColumnsSize[i]; ++j){
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

