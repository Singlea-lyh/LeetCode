/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.14%)
 * Likes:    13892
 * Dislikes: 509
 * Total Accepted:    2.7M
 * Total Submissions: 5.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sortArray(int* iNums, int* iSortNum, int iNumsSize){
    int i, j;
    int iTemp;

    for(i = 0; i < iNumsSize; ++i){
         iTemp = i;
        for(j = i + 1; j < iNumsSize - 1; ++j){
            if(iNums[iTemp] > iNums[j]){
                iTemp = j;
            }
        }

        iNums[i] = iNums[i] ^ iNums[j];
        iNums[j] = iNums[i] ^ iNums[j];
        iNums[i] = iNums[i] ^ iNums[j];
        iSortNum[i] = iTemp;
    }

    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int iTemp1, iTemp2;
    int  bFind = 0;
    int iSubNum;
    int iMidNum;

    int* iReturn = (int*)malloc(2*sizeof(int));
    int* iSortNum = (int*)malloc(numsSize*sizeof(int));

    sortArray(nums, iSortNum, numsSize);

    for(i = 0; i < numsSize; ++i){
        if(nums[i] >= target){
            break;
        }
        else 
        {
            iSubNum = target - nums[i];
        }

        iTemp1 = i + 1;
        iTemp2 = numsSize - 1;

        for(iTemp1, iTemp2; iTemp1 <= iTemp2; ){
            iMidNum = (iTemp1 + iTemp2) / 2;
            if(nums[iMidNum] != iSubNum){
                 if(nums[iMidNum] < iSubNum){
                    iTemp1 = iMidNum + 1;
                }
                else{
                    iTemp2 = iMidNum;
                }
            }
            else
            {
                bFind = 1;
                break;
            }
        }
        if(bFind == 1){
            iReturn[0] = iSortNum[i];
            iReturn[1] = iSortNum[iMidNum];
        }
        
    }

    free(iSortNum);

    return iReturn;

}

// @lc code=end

