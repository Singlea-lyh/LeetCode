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

void quicksort(int* piNums, int iNumsize, int iStart, int iEnd){
    int iLeft = iStart, iRight = iEnd;
    int iBase = piNums[iLeft];

    if(iLeft > iRight){
        return;
    }

    while(iLeft < iRight){
        while(iLeft < iRight && piNums[iRight] >= iBase){
            --iRight;
        }
        while(iLeft < iRight && piNums[iLeft] <= iBase ){
            ++iLeft;
        }

        if(iLeft < iRight){
            piNums[iLeft] = piNums[iLeft] ^ piNums[iRight];
            piNums[iRight] = piNums[iLeft] ^ piNums[iRight];
            piNums[iLeft] = piNums[iLeft] ^ piNums[iRight];
        }
    }

    piNums[iStart] = piNums[iLeft];
    piNums[iLeft] = iBase;

    quicksort(piNums, iNumsize, iStart, iLeft - 1);
    quicksort(piNums, iNumsize, iLeft + 1, iEnd);

    return;
}

void sort(int *piNum, int iNumsSize){
    if(iNumsSize < 2){
        return;
    }

    quicksort(piNum, iNumsSize, 0, iNumsSize - 1);

    return;
}

void backtrack(int *piNums, int iNumsSize, int iPos, int *piPath, int *piUsed, 
               int **ppiReturn, int *piReturnSize, int *piReturnCol){
    if(iPos == iNumsSize){
        ppiReturn[*piReturnSize] = (int*)malloc(sizeof(int) * iNumsSize);
        memset(ppiReturn[*piReturnSize], 0, sizeof(int) * iNumsSize);
        memcpy(ppiReturn[*piReturnSize], piPath, sizeof(int) * iNumsSize);
        piReturnCol[*piReturnSize] = iNumsSize;
        ++(*piReturnSize);
        return;
    }

    for(int i = 0; i < iNumsSize; ++i){     
        if(piUsed[i] == 0){
            if(i  > 0 && piNums[i - 1] == piNums[i] && !piUsed[i - 1]){
                continue;
            }  
            piUsed[i] = 1;
            piPath[iPos] = piNums[i];
            backtrack(piNums, iNumsSize, iPos + 1, piPath, piUsed, ppiReturn, piReturnSize, piReturnCol);
            piUsed[i] = 0;
        }
    }

    return;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ppiReturn = NULL;
    int iReturnSize = 1;
    int *piReturnCol = NULL;
    int *piPath = NULL;
    int *piUsed = NULL;

    sort(nums, numsSize);

    // for(int i= 0; i < numsSize; ++i){
    //     printf("%d, ", nums[i]);
    // }
    // printf("\n");

    for(int i = 1; i <= numsSize; ++i){
        iReturnSize *= i;
    }

    ppiReturn = (int**)malloc(sizeof(int*) * iReturnSize);
    piReturnCol = (int*)malloc(sizeof(int) * iReturnSize);
    piPath = (int*) malloc(sizeof(int)* numsSize);
    piUsed = (int*)malloc(sizeof(int) * numsSize);
    memset(ppiReturn, 0, (sizeof(int*) * iReturnSize));
    memset(piReturnCol, 0, (sizeof(int) * iReturnSize));
    memset(piPath, 0, (sizeof(int) * numsSize));
    memset(piUsed, 0, (sizeof(int) * numsSize));

    iReturnSize = 0;
    backtrack(nums, numsSize, 0, piPath, piUsed, ppiReturn, &iReturnSize, piReturnCol);

    *returnSize = iReturnSize;
    *returnColumnSizes = piReturnCol;
    return ppiReturn;
}
int main(){
    int **ppiReturn = NULL;
    int piNums[] = {1, 1, 2};
    int iNumSize = 3;
    int iReturnSize = 0;
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

