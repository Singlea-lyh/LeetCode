/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.53%)
 * Likes:    2032
 * Dislikes: 237
 * Total Accepted:    559.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int searchInsert(int* nums, int numsSize, int target){
    int iReturn = 0;
    int iLeft = 0, iRight = numsSize - 1;
    int iMid = 0;

    if(numsSize < 1 || target < nums[0] || (nums[0] == nums[numsSize - 1] && target <= nums[0])){
        return 0;
    }
    else if(target > nums[numsSize - 1]){
        return numsSize;       
    }

    while(iLeft <= iRight){
        iMid = (iLeft + iRight) / 2;
        if(nums[iMid] > target){
            iRight = iMid - 1;    
        }
        else if(nums[iMid] < target){
            iLeft = iMid + 1;
        }
        else{
            if(iLeft == iMid){
                return iLeft;
            }
            else{
                iRight = iMid - 1;
            } 
        }
        
    }

    if(iRight < 0){
        iReturn = 0;
    }
    else if(iLeft > numsSize - 1){
        iReturn = numsSize;
    }
    else{
        iReturn = iLeft;        
    }
    

    return iReturn;
}

int main(){
    int aiNums[] = {1,3,5,6};
    int iNumsSize = 4;
    int iTarget = 2;
    int iReturn = 0;

    iReturn = searchInsert(aiNums, iNumsSize, iTarget);

    printf("%d\n", iReturn);

    return 0;
}

// @lc code=end

