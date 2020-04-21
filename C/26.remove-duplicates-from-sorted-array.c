/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (43.72%)
 * Likes:    2262
 * Dislikes: 4714
 * Total Accepted:    881.6K
 * Total Submissions: 2M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int removeDuplicates(int* nums, int numsSize){
    int iStart = 0;
    int iEnd = 0;
    int iReturn = 0;
    
    if(numsSize < 2){
        return numsSize;
    }

    while(iEnd < numsSize){
        if(nums[iStart] == nums[iEnd]){
            ++iEnd;
        }
        else{
            nums[++iStart] = nums[iEnd++];
        }
    }

    iReturn = iStart + 1;

    return iReturn;

}


int main(){
    int aiNums[] = {0,0,1,1,1,2,2,3,3,4};
    int iNums = 10;
    int iReturn = 0;

    iReturn = removeDuplicates(aiNums, iNums);
    for(int i = 0; i < iReturn; ++i){
        printf("%d, ", aiNums[i]);
    }
    printf("\n");

    return 0;
}

// @lc code=end

