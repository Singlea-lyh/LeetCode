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

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

}
int main(){
    char ***pppcReturn = NULL;
    char **ppStr = {"eat", "tea", "tan", "ate", "nat", "bat"};
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

