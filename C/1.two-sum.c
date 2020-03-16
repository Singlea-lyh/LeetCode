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

/*
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
*/

//定义hash数据结构
struct hash_data{
    int iKey;
    int iData;
    struct hash_data *stNext;
};

//定义hash链表
struct hash_table{
    struct hash_data **stHead;
    int iHashLen;
};

//hash表初始化
int hash_init(struct hash_table *stHashTable, int iHashLen){
    if(iHashLen <= 0){
        return -1;
    }
    
    struct  hash_data **stHashData = (struct hash_data**) malloc(sizeof(struct hash_data*) * iHashLen);
    stHashTable->stHead = stHashData;
    memset(stHashTable->stHead, 0, iHashLen * sizeof(struct hash_data *));
    /*
    for(int i = 0; i < iHashLen; ++i){
        stHashTable->stHead[i] = NULL;
    }
    */
    if(stHashTable->stHead == NULL){
        return -1;
    }
    stHashTable->iHashLen = iHashLen;
    
    return 0;
}

//hash表释放
int hash_free(struct hash_table *stHashTable){
    if(stHashTable->stHead != NULL){
        for(int i = 0; i < stHashTable->iHashLen; ++i){
            struct hash_data *stTempHead = stHashTable->stHead[i];
            while(stTempHead != NULL){
                struct hash_data *stTemp = stTempHead;
                stTempHead = stTempHead->stNext;
                free(stTemp);
            }
        }
        free(stHashTable->stHead);
        stHashTable->stHead = NULL;
    }
    stHashTable->iHashLen = 0;

    return 0;
}

//hash表计算
int hash_cal(struct hash_table *stHashTable, int iKey){
    int Key = abs(iKey) % stHashTable->iHashLen;
    return Key;
}

//hash表插入
int hash_insert(struct hash_table *stHashTable, int iKey, int iVaule){
    struct hash_data *stDataTemp = (struct hash_data*)malloc(sizeof(struct hash_data));
    stDataTemp->stNext = NULL;
    if(stDataTemp == NULL){
        return -1;
    }

    stDataTemp->iKey = iKey;
    stDataTemp->iData = iVaule;
    int k = hash_cal(stHashTable, iKey);
    stDataTemp->stNext = stHashTable->stHead[k];
    stHashTable->stHead[k] = stDataTemp;

    return 0;
}

//hash表查找
struct hash_data* hash_find(struct hash_table* stHashTable, int iKey){
    int k = hash_cal(stHashTable, iKey);
    struct hash_data *stTempData = NULL;

    stTempData = stHashTable->stHead[k];

    while(stTempData != NULL){
        if(stTempData->iKey == iKey){
            return stTempData;
        }
        stTempData = stTempData->stNext;
    }

    return NULL;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *iReturn = (int *)malloc(2 * sizeof(int));
    int iCode = 0;
    int i = 0;
    int iSum1, iSum2;
    
    *returnSize = 0;

    struct hash_table *stHashTable = (struct hash_table*)malloc(sizeof(struct hash_table));

    hash_init(stHashTable, numsSize);

    for(i = 0; i < numsSize; ++i){
        iSum1 = nums[i];
        iSum2 = target - iSum1;
        struct hash_data *stTemp = hash_find(stHashTable, iSum2);

        if(stTemp != NULL && stTemp->iData != i){
            iReturn[0] = stTemp->iData;
            iReturn[1] = i;
            *returnSize = 2;
            break;
        }
        else{
                     
            hash_insert(stHashTable, iSum1, i);
        }
    }
    hash_free(stHashTable);
    free(stHashTable);

    return iReturn;     
}

// @lc code=end