/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.79%)
 * Likes:    5909
 * Dislikes: 721
 * Total Accepted:    813.2K
 * Total Submissions: 3.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
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
#include <math.h>
#include <string.h>

// #define NULL 0

void QuickSort(int* aiNum, int iLeft, int iRight){
    int iTemp = aiNum[iLeft];
    int iTempLeft = 0, iTempRight = 0, iSwap = 0;

    iTempLeft = iLeft;
    iTempRight = iRight;

    if(iTempLeft > iTempRight){
        return;

    }
    while(iTempLeft != iTempRight){
        while(aiNum[iTempRight] >= iTemp && iTempRight > iTempLeft){
            --iTempRight;
        }
        while(aiNum[iTempLeft] <= iTemp && iTempLeft < iTempRight){
            ++iTempLeft;
        }
        if(iTempLeft < iTempRight){
            // aiNum[iTempLeft] = aiNum[iTempLeft] ^ aiNum[iTempRight];
            // aiNum[iTempRight] = aiNum[iTempLeft] ^ aiNum[iTempRight];
            // aiNum[iTempLeft] = aiNum[iTempLeft] ^ aiNum[iTempRight];
            iSwap = aiNum[iTempLeft];
            aiNum[iTempLeft] = aiNum[iTempRight];
            aiNum[iTempRight] = iSwap;
        }
    }

    aiNum[iLeft] = aiNum[iTempLeft];
    aiNum[iTempLeft] = iTemp;

    QuickSort(aiNum, iLeft, iTempLeft - 1);
    QuickSort(aiNum, iTempLeft+1, iRight); 
}

int* ArraySort(int *nums, int numsSize){
    int *piReturn = (int*) malloc(sizeof(int) * numsSize);
    int iLeft = 0, iRight = numsSize - 1;

    for(int i = 0; i < numsSize; ++i){
        piReturn[i] = nums[i];
    }

    QuickSort(piReturn, iLeft, iRight);

    return piReturn;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ppaiReturnArray = NULL;
    int iReturnSize = 0;
    int* iSortNums = NULL;



    if(numsSize < 3){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    iSortNums = ArraySort(nums, numsSize);

    for(int i = 0; i < numsSize; ++i){
        printf("%d , " , iSortNums[i]);
    }
    printf("\n");

    ppaiReturnArray = (int**) malloc(sizeof(int*) * numsSize * 6);

    
    for(int i = 0; i < numsSize - 2; ){
        int iBase = iSortNums[i];
        int iLeft = i + 1, iRight = numsSize - 1;

        while(iLeft < iRight){
            while(iBase + iSortNums[iLeft] + iSortNums[iRight] != 0 && iLeft < iRight){
                if(iBase + iSortNums[iLeft] + iSortNums[iRight] > 0){
                    --iRight;
                }
                else if(iBase + iSortNums[iLeft] + iSortNums[iRight] < 0){
                    ++iLeft;
                }
                
            }
            // while(iBase + iSortNums[iLeft] + iSortNums[iRight] < 0 && iLeft < iRight){
            //     ++iLeft;
            // }
            if(iBase + iSortNums[iLeft] + iSortNums[iRight] == 0 && iLeft < iRight){
                ppaiReturnArray[iReturnSize] = (int*)malloc(sizeof(int) * 3);
                ppaiReturnArray[iReturnSize][0] = iBase;
                ppaiReturnArray[iReturnSize][1] = iSortNums[iLeft];
                ppaiReturnArray[iReturnSize][2] = iSortNums[iRight];
                iReturnSize++;
            }
            if(iRight > iLeft){
                int iLeftVaule = iSortNums[iLeft++], iRightVaule = iSortNums[iRight--];
                while(iLeft < iRight && iLeftVaule == iSortNums[iLeft]) {
                    ++iLeft;
                };
                while(iLeft < iRight && iRightVaule == iSortNums[iRight]){
                    --iRight;
                }
            }
        }

        while(++i < (numsSize - 1) && iSortNums[i] == iBase);
    }

    // *returnSize = numsSize;
    // **returnColumnSizes = iReturnSize;
    *returnSize = iReturnSize;

    *returnColumnSizes = (int*) malloc(sizeof(int) * 6 * numsSize);
    for(int i = 0; i < iReturnSize; ++i){
        (*returnColumnSizes)[i] = 3;
    }

    free(iSortNums);

    return ppaiReturnArray;    
}

int main(){
    int a[] = {-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4};

    int *iReturnSize = (int*)malloc(sizeof(int));
    int *iReturnColumnSizes = (int*)malloc(sizeof(int));

    int **pp3Sum = threeSum(a, 14, iReturnSize, &iReturnColumnSizes);

    for(int i = 0; i < *iReturnSize; ++i){
        for(int j = 0; j < 3; ++j){
            printf("%d  ", pp3Sum[i][j]);
        }
        printf("\n");    
    }

    for(int i = 0; i < *iReturnColumnSizes; ++i){
        free(pp3Sum[i]);
    }

    free(pp3Sum);

    // for(int i = 0; i < 6; ++i){
    //     printf("%d , " , a[i]);
    // }

    printf("\n");

    return 0;
}

// @lc code=end

