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

void nextPermutation(int* nums, int numsSize){

}

int main(){
    int aiNum[] = "";
    int iNumsSize = 0;

    nextPermutation(aiNum, iNumsSize);

    for(int i = 0; i < iNumsSize; ++i){
        printf("%d, ", aiNum[i]);
    }
    printf("\n");

    return 0;
}

// @lc code=end

