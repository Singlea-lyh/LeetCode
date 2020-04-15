/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.22%)
 * Likes:    4446
 * Dislikes: 206
 * Total Accepted:    912.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool isValid(char * s){
    bool bIsReturn = true;
    int iSLen = strlen(s);
    char* paSTemp = (char*)malloc(sizeof(char) * (iSLen + 1));
    int iHead = 0;
    int iTemp = 0;

    if(iSLen == 1){
        return false;
    }
    if(iSLen == 0){
        return true;
    }

    while(iTemp < iSLen){
        if(s[iTemp] == '(' || s[iTemp] == '[' || s[iTemp] == '{'){
            paSTemp[iHead++] = s[iTemp++];
        }
        else if(s[iTemp] == ')'){
            if(iHead > 0 && paSTemp[iHead - 1] == '('){
                --iHead;
                ++iTemp;
            }
            else{
                bIsReturn = false;
                break;
            }
        }
        else if(s[iTemp] == ']'){
            if(iHead > 0 && paSTemp[iHead - 1] == '['){
                --iHead;
                ++iTemp;
            }
            else{
                bIsReturn = false;
                break;
            } 
        }
        else if(s[iTemp] == '}'){
            if(iHead > 0 && paSTemp[iHead - 1] == '{'){
                --iHead;
                ++iTemp;
            }
            else{
                bIsReturn = false;
                break;
            } 
        }
    }

    if(iHead > 0){
        bIsReturn = false;
    }

    free(paSTemp);
    return bIsReturn;
}


int main(){
    char acParenthese[] = "((";
    bool bIsReturn = false;

    bIsReturn = isValid(acParenthese);

    if(bIsReturn){
        printf("true\n");
    }
    else{
        printf("false\n");
    } 

    return 0;    
}


// @lc code=end

