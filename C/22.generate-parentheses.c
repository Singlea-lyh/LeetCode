/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (60.40%)
 * Likes:    4449
 * Dislikes: 244
 * Total Accepted:    497.6K
 * Total Submissions: 821.2K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


char ** generateParenthesis(int n, int* returnSize){

}


int main(){
    int iReturnSize = 0;
    int iN = 0;
    char** ppacReturn = NULL;
    
    ppacReturn = generateParenthesis(iN, &iReturnSize);

    for(int i = 0; i < iReturnSize; ++i){
        printf("%s\n", ppacReturn[i]);
    }

    for(int i = 0; i < iReturnSize; ++i){
        free(ppacReturn[i]);
    }

    return 0;    
}



// @lc code=end

