/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.91%)
 * Likes:    2945
 * Dislikes: 1044
 * Total Accepted:    340.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// void QuickSort(int* nums, int iStart, int iEnd){
//     int iBase = iStart;
//     int iLeft = iStart;
//     int iRight = iEnd;

//     if(iLeft > iRight){
//         return;
//     }
    
//     while(iLeft != iRight){
//         while(iLeft < iRight && nums[iRight] >= nums[iBase]) --iRight;
//         while(iLeft < iRight && nums[iLeft] <= nums[iBase]) ++iLeft;

//         if(iLeft < iRight){
//             nums[iLeft] = nums[iLeft] ^ nums[iRight];
//             nums[iRight] = nums[iLeft] ^ nums[iRight];
//             nums[iLeft] = nums[iLeft] ^ nums[iRight]; 
//         }
//     }

//     nums[iBase] = nums[iBase] ^ nums[iLeft];
//     nums[iLeft] = nums[iBase] ^ nums[iLeft];
//     nums[iBase] = nums[iBase] ^ nums[iLeft];

//     QuickSort(nums, iStart, iLeft - 1);
//     QuickSort(nums, iLeft + 1, iEnd);

    
//     return;
// }

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

void nextPermutation(int* nums, int numsSize){
    int iLittle = numsSize - 1;
    int iIntervalMin = 0x7fffffff;
    int iSwap = 0;

    if(numsSize < 2){
        return;
    }

    while(iLittle > 0 && (nums[iLittle] <= nums[iLittle - 1])) iLittle--;

    if(iLittle == 0){
        QuickSort(nums, iLittle, numsSize - 1);        
    }
    else{
        int iLocal = iLittle - 1;
        while(iLittle < numsSize){
            int iInterval = nums[iLittle] - nums[iLocal];             
            if(iInterval > 0 && iIntervalMin > iInterval){
                iIntervalMin = iInterval;
                iSwap = iLittle;
            }
            iLittle++;
        }
        nums[iLocal] = nums[iLocal] ^ nums[iSwap];
        nums[iSwap] = nums[iLocal] ^ nums[iSwap];
        nums[iLocal] = nums[iLocal] ^ nums[iSwap];

        QuickSort(nums, iLocal + 1, numsSize - 1);
    }

    return;
}

int main(){
    int aiNum[] = {1,1};
    int iNumsSize = 2;

    nextPermutation(aiNum, iNumsSize);

    for(int i = 0; i < iNumsSize; ++i){
        printf("%d, ", aiNum[i]);
    }
    printf("\n");

    return 0;
}

// @lc code=end

