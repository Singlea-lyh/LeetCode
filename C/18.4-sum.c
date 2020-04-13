/*
 * @lc app=leetcode id=18 lang=c
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (32.75%)
 * Likes:    1616
 * Dislikes: 303
 * Total Accepted:    307.6K
 * Total Submissions: 937.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
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

void BubbleSort(int* acNums, int iNumSize){
    if(iNumSize < 2){
        return;
    }
    for(int i = iNumSize - 1; i > 0; --i){
        for(int j = 0; j < i; ++j){
            if(acNums[j] > acNums[j + 1]){
                acNums[j] = acNums[j] ^ acNums[j + 1];
                acNums[j + 1] = acNums[j] ^ acNums[j + 1];
                acNums[j] = acNums[j] ^ acNums[j + 1];
            }
        }
    }

    return;
}

int* Sort(int* acNums, int iNumSize){
    int* aiReturnNums = (int*) malloc(sizeof(int) * iNumSize);

    for(int i = 0; i < iNumSize; ++i){
        aiReturnNums[i] = acNums[i];
    }

    BubbleSort(aiReturnNums, iNumSize);

    for(int i = 0; i < iNumSize; ++i){
        printf("%d, ", aiReturnNums[i]);
    }
    printf("\n");

    return aiReturnNums;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int* paiSortNums = Sort(nums, numsSize);
    int iTempReturnSize = 0;
    int** ppaiReturn = NULL;

    if(numsSize < 4){
        *returnSize = iTempReturnSize;
        return ppaiReturn;
    }

    ppaiReturn = (int**)malloc(sizeof(int*) * numsSize * 4);

    int iFirst = 0;
    while(iFirst < numsSize - 3){
        if(paiSortNums[iFirst] + 3 * paiSortNums[iFirst + 1] > target){
            break;
        }
        if(paiSortNums[iFirst] + 3 * paiSortNums[numsSize - 1] < target){
            while(iFirst < numsSize - 4 && paiSortNums[iFirst] == paiSortNums[iFirst + 1]){
                ++iFirst;
            }
            ++iFirst;
            continue;
        }
        int iSecond = iFirst + 1;
        while(iSecond < numsSize - 2){
            if(paiSortNums[iFirst] + paiSortNums[iSecond] + 2 * paiSortNums[iSecond + 1] > target){
                break;
            }
            if(paiSortNums[iFirst] + paiSortNums[iSecond] + 2 * paiSortNums[numsSize - 1] < target){
                while(iSecond < numsSize - 3 && paiSortNums[iSecond] == paiSortNums[iSecond + 1]){
                    ++iSecond;
                }
                ++iSecond;
                continue;
            }

            int iStart = iSecond + 1, iEnd = numsSize - 1;

            while(iStart < iEnd){
                while(iStart < iEnd && paiSortNums[iFirst] + paiSortNums[iSecond] + paiSortNums[iStart] + paiSortNums[iEnd] != target){
                    if(paiSortNums[iFirst] + paiSortNums[iSecond] + paiSortNums[iStart] + paiSortNums[iEnd] > target){
                        --iEnd;
                    }
                    else{
                        ++iStart;
                    }
                }

                if(iStart < iEnd && paiSortNums[iFirst] + paiSortNums[iSecond] + paiSortNums[iStart] + paiSortNums[iEnd] == target){
                    ppaiReturn[iTempReturnSize] = (int*) malloc(sizeof(int) * 4);
                    ppaiReturn[iTempReturnSize][0] = paiSortNums[iFirst];
                    ppaiReturn[iTempReturnSize][1] = paiSortNums[iSecond];
                    ppaiReturn[iTempReturnSize][2] = paiSortNums[iStart];
                    ppaiReturn[iTempReturnSize][3] = paiSortNums[iEnd];
                    iTempReturnSize++;
                }
            
                if(iStart < iEnd){
                    int iStartVaule = paiSortNums[iStart++], iEndVaule = paiSortNums[iEnd--];
                    while(iStart < iEnd && paiSortNums[iStart] == iStartVaule){
                        ++iStart;
                    }
                    while(iStart < iEnd && paiSortNums[iEnd] == iEndVaule){
                        --iEnd;
                    }
                }
            }

            while(iSecond < numsSize - 3 && paiSortNums[iSecond] == paiSortNums[iSecond + 1]){
                iSecond++;
            }
            ++iSecond;
        }

        while(iFirst < (numsSize - 4) && paiSortNums[iFirst] == paiSortNums[iFirst + 1]){
            iFirst++;
        }
        ++iFirst;
    }

    *returnSize = iTempReturnSize;

    *returnColumnSizes = (int*) malloc(sizeof(int) * iTempReturnSize);

    for(int i = 0; i < iTempReturnSize; ++i){
        (*returnColumnSizes)[i] = 4;
    }


    free(paiSortNums);
    return ppaiReturn;

}

int main(){
    int aiNums[] = {-4,-3,-2,-1,0,0,1,2,3,4};
    int iNumSize = 10;
    int iTarget = 0;
    int** ppiReturn = NULL;
    int iRturnSize = 0;
    int* piReturnColumnSize = (int*)malloc(sizeof(int));

    ppiReturn = fourSum(aiNums, iNumSize, iTarget, &iRturnSize, &piReturnColumnSize);

    for(int i = 0; i < iRturnSize; ++i){
        for(int j = 0; j < piReturnColumnSize[i]; ++j){
            printf("%d, ", ppiReturn[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < iRturnSize; ++i){
        free(ppiReturn[i]);
    }
    free(ppiReturn);
    free(piReturnColumnSize);
    
    return 0;
}


// @lc code=end

