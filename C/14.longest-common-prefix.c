/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.75%)
 * Likes:    2162
 * Dislikes: 1716
 * Total Accepted:    671.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char * longestCommonPrefix(char ** strs, int strsSize){
    int iMinStrLen = __INT_MAX__;
    char *pReturn = NULL;
    int iBreak = 0;

    for(int i = 0; i < strsSize; ++i){
        iMinStrLen = (iMinStrLen < strlen(strs[i]) ? iMinStrLen : strlen(strs[i]));
    }

    if(iMinStrLen == 0 || strsSize == 0){
        return "";
    }

    pReturn = (char*) malloc(sizeof(char) * (iMinStrLen + 1));
    memset(pReturn, 0, iMinStrLen + 1);

    for(int i = 0; i < iMinStrLen; ++i){
        int j = 0;
        char cTemp = strs[j][i];

        for(j = 1; j < strsSize; ++j){
            if(cTemp != strs[j][i]){
                iBreak = 1;
                break;
            }
        }

        if(j == strsSize){
            pReturn[i] = cTemp;
        }

        if(iBreak){
            return pReturn;
        }
 
    }

    return pReturn;

}


int main(){
    // char acStr[3][10] = {"flower","flow","flight"};
    int isizesSize = 3;
    char **acStr = (char**)malloc(sizeof(char*) * isizesSize);

    for(int i = 0; i < isizesSize; ++i){
        *(acStr+i) = (char*) malloc(sizeof(char) * 10);
        memset(*(acStr+i), 0, 10);
    }

    char a[10] = {0};

   // sprintf(acStr[0], "%s", "flower");
    // sprintf(acStr[1], "%s", "flow");
    // sprintf(acStr[2], "%s", "flight"); 
    
    sprintf(*acStr, "%s", "flower");
    sprintf(*(acStr+1), "%s", "flow");
    sprintf(*(acStr+2), "%s", "flight"); 
    // memcmp(acStr[0], "flower", 10);
    // memcmp(acStr[1], "flow", 10);
    // memcmp(acStr[2], "flight", 10);


    // memcmp(acStr , "flower", 10);
    // memcmp(acStr+1  , "flow", 10);
    // memcmp(acStr+2 , "flight", 10);

    char *pacReturn = longestCommonPrefix(acStr, 3);
    // printf("%s\n", a);

    // for(int i = 0; i < isizesSize; ++i){
    //    printf("%s\n", acStr[i]);
    // }
    
    printf("%s\n", pacReturn);

    for(int i = 0; i < isizesSize; ++i){
       free(acStr[i]);
    }

    free(pacReturn);

    return 0;
}

// @lc code=end

