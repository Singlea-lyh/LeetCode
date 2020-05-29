/*
 * @lc app=leetcode id=45 lang=c
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.87%)
 * Likes:    2302
 * Dislikes: 126
 * Total Accepted:    247.5K
 * Total Submissions: 819.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// int recurrence(int* pcNums, int iIndex, int iJumpNum, int iNumSize){
//     int iReturn = 0;
//     int iBase = pcNums[iIndex];

//     if(iIndex == iNumSize){
//         return iReturn;
//     }
//     else if(iIndex > iNumSize){
//         iReturn = 1;
//         return iReturn;        
//     }

//     for(int i = iBase; i > 0; --i ){
//         int iRet = 0;
//         iRet = recurrence(pcNums, iIndex + iBase, iBase, iNumSize);
//         if(iRet == 0){
//             continue;
//         }
//         else{
//             iReturn = 1 + iRet;
//             break;
//         }
//     }
//     return iReturn;
// }

// int jump(int* nums, int numsSize){
//     int iReturn = 0;
//     int iPosition = numsSize - 1;
//     int iStep = 0;

//     if(numsSize < 0){
//         return iReturn;
//     }

//     while (iPosition > 0){
//        for(int i = 0; i < iPosition; ++i){
//            if(i + nums[i] >= iPosition){
//                iPosition = i;
//                ++iStep;
//                break;
//            }
//        }
//     }
//     iReturn = iStep;   

//     return iReturn;
// }

int jump(int* nums, int numsSize){
    int iReturn = 0;
    int iPosition = 0;
    int iEnd = 0;
    int iStep = 0;

    if(numsSize < 0){
        return iReturn;
    }

    for(int i = 0; i < numsSize - 1; ++i){
        iPosition = (iPosition > (i + nums[i])? iPosition : (i + nums[i]));
        if(i == iEnd){
            iEnd = iPosition;
            ++iStep;
        }
    }

    iReturn = iStep;
    return iReturn;
}

int main(){
    int aiNum[] = {2,3,1,1,4};
    int iNumSize = 5;
    int iReturn = 0;

    iReturn = jump(aiNum, iNumSize);
    printf("%d\n", iReturn);

    return 0;
}

// @lc code=end

