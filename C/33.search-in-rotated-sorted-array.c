/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.69%)
 * Likes:    4470
 * Dislikes: 427
 * Total Accepted:    679.3K
 * Total Submissions: 2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dichotomy(int* nums, int iStart, int iEnd, int iTarget){
    int iLeft = iStart, iRight = iEnd;
    int iMid = 0;
    int iReturn = 0;

    if(iLeft == iRight && nums[iLeft] != iTarget){
        return -1;
    }
    if(nums[iLeft] == iTarget){
        return iLeft;
    }
    else if(nums[iRight] == iTarget){
        return iRight;
    }
    else{
        iMid = (iLeft + iRight) / 2;
        if(nums[iMid] == iTarget){
            return iMid;
        }
        else if(nums[iLeft] < nums[iMid] && nums[iLeft] < iTarget && nums[iMid] > iTarget){
            iReturn = dichotomy(nums, iLeft, iMid - 1, iTarget);
        }
        else if(nums[iLeft] < nums[iMid] && (nums[iMid] < iTarget || nums[iLeft] > iTarget)){
            iReturn = dichotomy(nums, iMid + 1, iRight, iTarget);
        }
        else if(nums[iLeft] > nums[iMid] && nums[iMid] < iTarget && nums[iRight] > iTarget){
            iReturn = dichotomy(nums, iMid + 1, iRight, iTarget);
        }
        else if(nums[iLeft] > nums[iMid] && (nums[iMid] > iTarget || nums[iRight] < iTarget)){
            iReturn = dichotomy(nums, iLeft, iMid - 1, iTarget);
        }
        else{
            iReturn = dichotomy(nums, iMid + 1, iRight, iTarget);
        }
    }

    return iReturn;
}

int search(int* nums, int numsSize, int target){
    int iReturn = 0;

    if(numsSize < 1){
        return -1;
    }

    iReturn = dichotomy(nums, 0, numsSize - 1, target);

    return iReturn;
}


int main(){
    int aiNums[] = {4,5,6,7,0,1,2};
    int iNumsSize = 7;
    int iTarget = 3;
    int iReturn = 0;

    iReturn = search(aiNums, iNumsSize, iTarget);

    printf("%d\n", iReturn);

    return 0;
}




// @lc code=end

