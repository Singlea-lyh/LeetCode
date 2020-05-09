/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.29%)
 * Likes:    3011
 * Dislikes: 134
 * Total Accepted:    464.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void dichotomy(int* piNums, int iStart, int iEnd, int iTarget, int* piReturnSiee, int* piReturn ){
    int iLeft = iStart, iRight = iEnd;
    int iMid = 0;
    
    iMid = (iLeft + iEnd) / 2;

    if(iLeft == iRight && piNums[iLeft] == iTarget){
        if( piReturn[0] == -1 || (piReturn[0] != -1 && piReturn[0] > iMid)){
            piReturn[0] = iLeft;
        }
        if(piReturn[1] == -1 || (piReturn[1] != -1 && piReturn[1] < iMid)){
            piReturn[1] = iRight;
        }
        return;
    }
    else if(iLeft == iRight && piNums[iLeft] != iTarget){
        return;
    }

    if(piNums[iMid] == iTarget){
        if(piReturn[0] == -1 || (piReturn[0] != -1 && piReturn[0] > iMid)){
            piReturn[0] = iMid;
            if(iLeft < iMid){
                dichotomy(piNums, iLeft, iMid - 1, iTarget, piReturnSiee, piReturn);
            }
        }
        if(piReturn[1] == -1 || (piReturn[1] != -1 && piReturn[1] < iMid)){
            piReturn[1] = iMid;
            if(iMid < iRight){
                dichotomy(piNums, iMid + 1, iRight, iTarget, piReturnSiee, piReturn);
            }
           
        }
    }
    else if(piNums[iMid] > iTarget && iMid > iLeft){
        dichotomy(piNums, iLeft, iMid - 1, iTarget, piReturnSiee, piReturn);
    }
    else if(piNums[iMid] < iTarget && iMid < iRight){
        dichotomy(piNums, iMid + 1, iRight, iTarget, piReturnSiee, piReturn);
    }

    return;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* piReturn = (int*)malloc(sizeof(int) * 2);

    piReturn[0] = -1;
    piReturn[1] = -1;
    *returnSize = 2;

    if(numsSize < 1 || nums[0] > target || nums[numsSize - 1] < target){
        return piReturn;
    }
    if(nums[0] == target && nums[numsSize - 1] == target){
        piReturn[0] = 0;
        piReturn[1] = numsSize - 1;
        return piReturn;
    }

    dichotomy(nums, 0, numsSize - 1, target, returnSize, piReturn);

    return piReturn;

}

int main(){
    int aiNums[] = {1,2,3,3,3,3,4,5,9};
    int iNumsSize = 9;
    int iTarget = 3;
    int iReturnSize = 0;
    int* piReturn = NULL;

    piReturn = searchRange(aiNums, iNumsSize, iTarget, &iReturnSize);

    printf("[ ");
    for(int i = 0; i < iReturnSize; ++i){
        printf("%d ", piReturn[i]);
    }
    printf("]\n");

    free(piReturn);

    return 0;
}

// @lc code=end

