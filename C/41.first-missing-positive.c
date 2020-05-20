/*
 * @lc app=leetcode id=41 lang=c
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.98%)
 * Likes:    3130
 * Dislikes: 759
 * Total Accepted:    314.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    
    if(numsSize < 1){
        return 1;
    }
    if(numsSize == 1 && nums[0] == 1){
        return 2;
    }

    for(i = 0; i < numsSize; ++i){
        if(nums[i] == 1){
            break;
        }        
    }
    if(i == numsSize){
        return 1;
    }
    for(i = 0; i < numsSize; ++i){
        if(nums[i] == 0 || nums[i] < 0 || nums[i] > numsSize){
            nums[i] = 1;
        }
    }


    for(i = 0; i < numsSize; ++i){
        int iIndex = (nums[i] < 0)? (-nums[i]) :nums[i];
        if(nums[iIndex % numsSize] < 0){
            continue;
        }
        else{
            nums[iIndex % numsSize] *= (-1);
        }
    }

    for(i = 1; i < numsSize; ++i){
        if(nums[i] > 0){
            return i;
        }        
    }


    if(i == numsSize && nums[0] > 0){
        return numsSize;
    }
    
    return numsSize + 1;
}

int main(){
    int iReturn = 0;
    int aiNum[] = {1,2,3,4,5};
    int iNumSize = 5;

    iReturn = firstMissingPositive(aiNum, iNumSize);

    printf("%d\n", iReturn);

    return 0;
}
// @lc code=end

