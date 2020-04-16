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

void dfsgenerate(int iParentheses, int iLeft, int iRight, int iIndex, int *piReturnSize, char* pacItem, char** ppacReturn){
    if(iLeft == 0 && iRight == 0){
        ppacReturn[*piReturnSize] = (char*) malloc(sizeof(char) * (2 * iParentheses + 1));
        sprintf( ppacReturn[*piReturnSize], "%s\0", pacItem);
        (*piReturnSize)++;
        return;
    }

    if(iLeft > iRight){
        return;
    }

    if(iLeft > 0){
        pacItem[iIndex] = '(';
        dfsgenerate(iParentheses ,iLeft - 1, iRight, iIndex + 1, piReturnSize, pacItem, ppacReturn);  
    }

    if(iRight > 0){
        pacItem[iIndex] = ')';        
        dfsgenerate(iParentheses, iLeft, iRight - 1, iIndex + 1, piReturnSize, pacItem, ppacReturn);

    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** ppacReturn = (char**)malloc(sizeof(char*) * 5000);
    char* pacItem = (char*) malloc(sizeof(char) * (2 * n + 1));
    int iReturnSize = 0;
    int iLeft = n, iRight = n;
    int iIndex = 0;

    if(n == 0){
        *returnSize = iReturnSize;
        return NULL;
    }

    memset(pacItem, 0, 2 * n + 1);

    dfsgenerate(n, iLeft, iRight, iIndex, &iReturnSize, pacItem, ppacReturn);

    *returnSize = iReturnSize;

    return ppacReturn;
}


int main(){
    int iReturnSize = 0;
    int iN = 8;
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

