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

int backtrace(int* piCandidates, int iCandidatesSize, int iTarget,int* piReturnSize, int** ppReturn,  
              int* piReturnCol, int* piTempBuf, int iIndex,  int iBufPox){
    
    if(iTarget == 0){
        return 0;
    }
    if(iTarget < 0){
        return -1;
    }

    for(int i = iIndex; i < iCandidatesSize; ++i){

        if(piTempBuf[iBufPox] == piCandidates[i]){
            continue;
        }

        piTempBuf[iBufPox] = piCandidates[i];

        int iTemp = backtrace(piCandidates, iCandidatesSize, iTarget - piCandidates[i], piReturnSize, 
                            ppReturn, piReturnCol, piTempBuf, i + 1, iBufPox + 1);
        
        if(iTemp == 0){
            ppReturn[*piReturnSize] = (int*)malloc(sizeof(int) * (iBufPox + 1));
            memset(ppReturn[*piReturnSize], 0, sizeof(int) * (iBufPox + 1));
            memcpy(ppReturn[*piReturnSize], piTempBuf, sizeof(int) * (iBufPox + 1));
            piReturnCol[*piReturnSize] = iBufPox + 1;
            (*piReturnSize)++;
            return 1;
        }
        if(iTemp == -1){
            // piTempBuf[iBufPox] = 0;
            return 1;
        }
        // if(iTemp == 1){
        //     int iBase = piCandidates[i];
        //     while((i+1) < iCandidatesSize && iBase == piCandidates[i + 1]) ++i;
        // }
    }
    // piTempBuf[iBufPox] = 0;
    return 1;
}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int** ppReturn = NULL;
    int* piReturnCol = NULL;
    int iReturnSize = 0;
    int* piTempBuff = NULL;

    if(candidatesSize < 1){
        *returnSize = 0;
        return ppReturn;
    }

    ppReturn = (int**)malloc(sizeof(int*) * MAX_LEN);
    piReturnCol = (int*)malloc(sizeof(int) * MAX_LEN);
    memset(piReturnCol, 0, sizeof(int)*MAX_LEN);
    piTempBuff = (int*)malloc(sizeof(int) * MAX_LEN);
    memset(piTempBuff, 0, sizeof(int) * MAX_LEN);

    // for(int i = 0; i < MAX_LEN; ++i){
    //     ppReturn[i] = (int*)malloc(sizeof(int) * MAX_LEN);
    //     memset(ppReturn[i], 0, sizeof(int) * MAX_LEN);
    // }

    Sort(candidates, candidatesSize);

    for(int i = 0; i < candidatesSize; ++i){
        printf("%d, ", candidates[i]);
    }
    printf("\n");

    backtrace(candidates, candidatesSize, target, &iReturnSize, ppReturn, piReturnCol, piTempBuff,  0, 0);

    *returnColumnSizes = piReturnCol;
    *returnSize = iReturnSize;

    return ppReturn;
}


int main(){
    int aiCandidates[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 5,};
    int iCandidatesSize = 11;
    int iTarget = 5;
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

    free(ppReturnColumnsSize);

    return 0;
}

// @lc code=end

