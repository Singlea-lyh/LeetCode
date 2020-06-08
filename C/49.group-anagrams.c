/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (53.37%)
 * Likes:    3329
 * Dislikes: 174
 * Total Accepted:    659.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct strIndexInfo{
    int iIndex;
    char *pcStr;
}strIndexInfo_ST;

int strcompare(const void *pc1, const void *pc2){
    struct strIndexInfo *pstStr1 = (struct strIndexInfo*)pc1;
    struct strIndexInfo *pstStr2 = (struct strIndexInfo*)pc2;

    return strcmp(pstStr1->pcStr, pstStr2->pcStr);
}

int charcmp(const void *pc1, const void *pc2){
    return *(char*)pc1 - *(char*)pc2;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int iReturn = 0;
    int *pcReturnCol = NULL;
    char ***pppcReturn = NULL;
    struct strIndexInfo *pstStrIndex = NULL;

    int iLeft = 0;
    int iRight = 0;
    
    if(strsSize == 0){
        *returnSize = iReturn;
        return NULL;
    }

    pcReturnCol = (int*)malloc(sizeof(int) * strsSize);
    pppcReturn = (char***)malloc(sizeof(char**) * strsSize);
    pstStrIndex = (struct strIndexInfo *)malloc(sizeof(struct strIndexInfo ) * strsSize);

    memset(pcReturnCol, 0, sizeof(int) * strsSize);
    memset(pppcReturn, 0, (sizeof(char**) * strsSize));
    memset(pstStrIndex, 0, sizeof(struct strIndexInfo ) * strsSize);

    for(int i = 0; i < strsSize; ++i){
        pstStrIndex[i].iIndex = i;
        pstStrIndex[i].pcStr = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));
        memset(pstStrIndex[i].pcStr, 0, sizeof(char) * (strlen(strs[i]) + 1));
        strcpy(pstStrIndex[i].pcStr, strs[i]);
        qsort(pstStrIndex[i].pcStr, strlen(pstStrIndex[i].pcStr), sizeof(pstStrIndex[i].pcStr[0]), charcmp);
    }

    qsort(pstStrIndex, strsSize, sizeof(pstStrIndex[0]), strcompare);

    while(iRight <= strsSize){
        if(iRight == strsSize || (iRight < strsSize && strcmp(pstStrIndex[iLeft].pcStr, pstStrIndex[iRight].pcStr) != 0)){
            int iNums = iRight - iLeft;
            pppcReturn[iReturn] = (char**)malloc(sizeof(char*) * iNums);
            memset(pppcReturn[iReturn], 0, sizeof(char*) * iNums);
            pcReturnCol[iReturn] = iNums;
            for(int i = 0; i < iNums; ++i){
                pppcReturn[iReturn][i] = (char*)malloc(sizeof(char) * (strlen(pstStrIndex[iLeft].pcStr) + 1));
                memset(pppcReturn[iReturn][i], 0, sizeof(char) * (strlen(pstStrIndex[iLeft].pcStr) + 1));
                strcpy(pppcReturn[iReturn][i], strs[pstStrIndex[iLeft].iIndex]);
                ++iLeft;
            }
            ++iReturn;
        }
        ++iRight;
    }

    *returnSize = iReturn;
    *returnColumnSizes = pcReturnCol;

    printf("Return Size : %d\n", iReturn);

    return pppcReturn;    
}
int main(){
    char ***pppcReturn = NULL;
    char *ppStr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int iStrSize = 6;
    int iReturn = 0;
    int *piReturnCol = NULL;

    pppcReturn = groupAnagrams(ppStr, iStrSize, &iReturn, &piReturnCol);

    for(int i = 0; i < iReturn; ++i){
        for(int j = 0; j < piReturnCol[i]; ++j){
            printf("%s, ", pppcReturn[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < iReturn; ++i){
        for(int j = 0; j < piReturnCol[i]; ++j){
            free(pppcReturn[i][j]);
        }
        printf("\n");
    }
    free(pppcReturn);
    free(piReturnCol);

    return 0;
}


// @lc code=end

