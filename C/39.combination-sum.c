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

#define MAX_LEN 256

void QuickSort(int* piCandidates, int iStart , int iEnd){
    int iLeft = iStart, iRight = iEnd;
    int iBase = piCandidates[iStart];

    if(iLeft > iRight){
        return;
    }
    
    while(iLeft != iRight){
        while(iLeft < iRight && piCandidates[iRight] >= iBase) --iRight;
        while(iLeft < iRight && piCandidates[iLeft] <= iBase) ++iLeft;

        if(iLeft < iRight){
            piCandidates[iLeft] = piCandidates[iLeft] ^ piCandidates[iRight];
            piCandidates[iRight] = piCandidates[iLeft] ^ piCandidates[iRight];
            piCandidates[iLeft] = piCandidates[iLeft] ^ piCandidates[iRight];
        }
    }

    piCandidates[iStart] = piCandidates[iLeft];
    piCandidates[iLeft] = iBase;

    QuickSort(piCandidates, iStart, iLeft - 1);
    QuickSort(piCandidates, iLeft + 1, iEnd);

    return;
}

void Sort(int* piCandidates, int iCandidatesSize){
    QuickSort(piCandidates, 0, iCandidatesSize - 1);

    return;
}

int backtrace(int* piCandidates, int iCandidatesSize, int iTarget, int** ppReturn, int* piReturnSize , int* piReturnCol,
              int iRetPos, int iIndex ){
  
    if(iTarget == 0){
        return 0;
    }
    if(iTarget < 0){
        return -1;
    }

    for(int i = iIndex; i < iCandidatesSize; ++i){
        ppReturn[*piReturnSize][iRetPos] = piCandidates[i];

        int iTemp = backtrace(piCandidates, iCandidatesSize, iTarget - piCandidates[i], ppReturn, 
                            piReturnSize, piReturnCol, iRetPos + 1, i);
        
        if(iTemp == 0){
            piReturnCol[*piReturnSize] = iRetPos + 1;
            memcpy(ppReturn[*piReturnSize + 1] , ppReturn[*piReturnSize], sizeof(int) * (iRetPos + 1));
            (*piReturnSize)++;
            return 1;
        }
        if(iTemp == -1){
            return 1;
        }
    }

    return 1;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int** ppReturn = NULL;
    int* piReturnCol = NULL;
    int iReturnSize = 0;

    if(candidatesSize < 1){
        *returnSize = 0;
        return ppReturn;
    }

    ppReturn = (int**)malloc(sizeof(int*) * MAX_LEN);
    piReturnCol = (int*)malloc(sizeof(int) * MAX_LEN);
    memset(piReturnCol, 0, sizeof(int)*MAX_LEN);

    for(int i = 0; i < MAX_LEN; ++i){
        ppReturn[i] = (int*)malloc(sizeof(int) * MAX_LEN);
        memset(ppReturn[i], 0, sizeof(int) * MAX_LEN);
    }

    Sort(candidates, candidatesSize);


    for(int i = 0; i < candidatesSize; ++i){
        printf("%d, ", candidates[i]);
    }
    printf("\n");

    backtrace(candidates, candidatesSize, target, ppReturn, &iReturnSize, piReturnCol, 0, 0);

    for(int i = iReturnSize; i < MAX_LEN; ++i){
        free(ppReturn[i]);
    }

    *returnSize = iReturnSize;
    *returnColumnSizes = piReturnCol;
    return ppReturn;
}

int main(){
    int aiCandidates[] = {2,3,6,7};
    int iCandidatesSize = 4;
    int iTarget = 6;
    int iReturnSize = 0;
    int* ppReturnColumnsSize = NULL;
    int** ppReturn = NULL;

    ppReturn = combinationSum(aiCandidates, iCandidatesSize, iTarget, &iReturnSize, &ppReturnColumnsSize);

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

