/*
 * @lc app=leetcode id=32 lang=c
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.52%)
 * Likes:    3059
 * Dislikes: 131
 * Total Accepted:    265.1K
 * Total Submissions: 958.2K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int longestValidParentheses(char * s){
    int iSLen = strlen(s);
    int iMaxzValid = 0;
    int iMaxParenthess = 0;
    int i = 0, j = 0;
    int iReturn = 0;
    char* pacStack = NULL; 

    if(iSLen < 2){
        return iReturn;
    }

    pacStack = (char*)malloc(sizeof(char) * iSLen);

    while(i < iSLen){

    }



    return iReturn;
}

int main(){
    int aiNum[] = "(()";
    int iReturn = 0;

    iReturn = nextPermutation(aiNum);

    printf("%d\n", iReturn);

    return 0;
}
// @lc code=end

