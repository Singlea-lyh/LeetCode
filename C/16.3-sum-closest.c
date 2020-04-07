/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.73%)
 * Likes:    1744
 * Dislikes: 123
 * Total Accepted:    437.7K
 * Total Submissions: 956.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0
typedef int bool;


#define  ABS(a)  (a > 0) ? a : -a

void ChoseSort(int* piNums, int iNumsSize){
    int iTempNum = 0;

    for(int i = 0; i < iNumsSize - 1; ++i){
        iTempNum = i;
        for(int j = i + 1; j < iNumsSize; ++j){
            if(piNums[iTempNum] > piNums[j]){
                iTempNum = j;
            }
        }
        if(i != iTempNum){
            piNums[i] = piNums[i] ^ piNums[iTempNum];
            piNums[iTempNum] = piNums[i] ^ piNums[iTempNum];
            piNums[i] = piNums[i] ^ piNums[iTempNum];
        }
    }

    return;
}


int* Sort(int* piNums, int iNumsSize){
    int* pTempNums = (int*)malloc(sizeof(int) * iNumsSize);

    for(int i = 0; i < iNumsSize; ++i){
        pTempNums[i] = piNums[i];
    }

    ChoseSort(pTempNums, iNumsSize);

    return pTempNums;
}



int threeSumClosest(int* nums, int numsSize, int target){
    int* piTempNums = NULL;
    int iClosest = __INT_MAX__;
    int iReturn = __INT_MAX__;
    bool bIsZero = false;

    if(numsSize < 3){
        return __INT_MAX__;
    }

    piTempNums = Sort(nums, numsSize);

    for(int i = 0; i < numsSize; ++i){
        printf("%d, ", piTempNums[i]);
    }
    printf("\n");

    for(int i = 0; i < numsSize - 2; ++i){
        int iBase = piTempNums[i];
        int iLeft = i + 1, iRight = numsSize - 1;

        while(iLeft < iRight){
            int iSum = piTempNums[iLeft] + piTempNums[iRight] + iBase;
            if(abs(iSum - target) < abs(iClosest)){
                iClosest = iSum - target;
                iReturn = iSum;
            }
            if(iSum > target){  
                --iRight;
            }
            else if(iSum < target){                   
                ++iLeft;
            }
            else{   
                iReturn = target;
                bIsZero = true;
                break;
            }          
        }
        if(bIsZero){
            break;
        }

    }

    free(piTempNums);
    
    return iReturn;
}

int main(){
    int aiNums[] = {-1, 2, 1, -4};
    int iTarget = 1;
    int iReturn = 0;

    iReturn = threeSumClosest(aiNums, 4, iTarget);

    printf("%d\n", iReturn);

    return 0;
}


// @lc code=end

