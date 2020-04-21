/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (47.19%)
 * Likes:    1257
 * Dislikes: 2487
 * Total Accepted:    563.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 * 
 * Your function should return length = 5, with the first five elements of nums
 * containing 0, 1, 3, 0, and 4.
 * 
 * Note that the order of those five elements can be arbitrary.
 * 
 * It doesn't matter what values are set beyond the returned length.
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
 * int len = removeElement(nums, val);
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


void QuickSort(int* piNums, int iLeft, int iRight){
    int iBase = piNums[iLeft];
    int iTempLeft = iLeft, iTempRight = iRight;

    if(iTempLeft > iTempRight){
        return;

    }
    
    while(iTempLeft !=  iTempRight){
        while(iTempLeft < iTempRight && iBase <= piNums[iTempRight]) --iTempRight;
        while(iTempLeft < iTempRight && iBase >= piNums[iTempLeft]) ++iTempLeft;

        if(iTempLeft < iTempRight){
            piNums[iTempLeft] = piNums[iTempLeft] ^ piNums[iTempRight];
            piNums[iTempRight] = piNums[iTempLeft] ^ piNums[iTempRight];
            piNums[iTempLeft] = piNums[iTempLeft] ^ piNums[iTempRight];
        }
    }

    piNums[iLeft] = piNums[iTempLeft];
    piNums[iTempLeft] = iBase;

    QuickSort(piNums, iLeft, iTempLeft - 1);
    QuickSort(piNums, iTempLeft + 1, iRight);

}

void Sort(int* piNums, int iNumSize){
    QuickSort(piNums, 0, iNumSize - 1);
    // for(int i = 0; i < iNumSize; ++i){
    //     printf("%d, ", piNums[i]);
    // }
    // printf("\n");
}

// int removeElement(int* nums, int numsSize, int val){
//     int iStart = 0;
//     int iEnd = 0;
//     int iReturn = 0;

//     Sort(nums, numsSize);

//     while(iEnd < numsSize){
//         if(nums[iEnd] < val){
//             ++iStart;
//             ++iEnd;
//         }
//         else if(nums[iEnd] == val){
//             ++iEnd;
//         }
//         else{
//             nums[iStart++] = nums[iEnd++];
//         }
//     }

//     iReturn = iStart;

//     return iReturn;
// }

int removeElement(int* nums, int numsSize, int val){
    int iStart = 0;
    int iEnd = 0;
    int iReturn = 0;
    
    while(iEnd < numsSize){
        if(nums[iEnd] == val){
            ++iEnd;
        }
        else{
            nums[iStart++] = nums[iEnd++];
        }

    }

    iReturn = iStart;

    return iReturn;
}

int main(){
    int aiNums[] = {0,1,2,2,3,0,4,2};
    int iNums = 8;
    int iVal = 2;
    int iReturn = 0;

    iReturn = removeElement(aiNums, iNums, iVal);
    for(int i = 0; i < iReturn; ++i){
        printf("%d, ", aiNums[i]);
    }
    printf("\n");

    return 0;
}

// @lc code=end

