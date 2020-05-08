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
 * (((()(((()(
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// int longestValidParentheses(char * s){
//     int iSLen = strlen(s);
//     int iMaxValid = 0;
//     int iMaxParenthess = 0;
//     int i = 0, j = 0;
//     int iLeft = 0, iRight = 0;
//     int iReturn = 0;
//     // char* pacStack = NULL; 

//     if(iSLen < 2){
//         return iReturn;
//     }

//     // pacStack = (char*)malloc(sizeof(char) * iSLen);

//     // while(i < iSLen){
//     //     char cTemp = s[i];

//     //     if(cTemp == '('){

//     //     }

//     // }

//     while(i < iSLen){
//         if(s[i] == '('){
//             ++iLeft;
//         }
//         else{
//             ++iRight;
//         }
//         ++iMaxValid;
//         if(iLeft == iRight){
//             if(iMaxValid > iMaxParenthess){            
//                 iMaxParenthess = iMaxValid;
//             }
//         }
//         else if (iRight > iLeft){
//             iMaxValid = 0;  
//             iLeft = 0;
//             iRight = 0;          
//         }
//         ++i;
//     }

//     iMaxValid = 0;
//     iLeft = 0;
//     iRight = 0;
//     i = iSLen - 1;

//     while(i >= 0){
//         if(s[i] == '('){
//             ++iLeft;
//         }
//         else{
//             ++iRight;
//         }

//         ++iMaxValid;

//         if(iLeft == iRight){
//             if(iMaxValid > iMaxParenthess){            
//                 iMaxParenthess = iMaxValid;
//             }
//         }
//         else if (iRight < iLeft){
//             iMaxValid = 0;  
//             iLeft = 0;
//             iRight = 0;          
//         }
//         --i;
//     }


//     iReturn = iMaxParenthess;

//     return iReturn;
// }


// int longestValidParentheses(char * s){
//     int iSLen = strlen(s);
//     int iMaxValid = 0;
//     int iMaxParenthess = 0;
//     int i = 0, j = 0;
//     int iReturn = 0;
//     int* pacStack = NULL; 

//     if(iSLen < 2){
//         return iReturn;
//     }

//     pacStack = (int*)malloc(sizeof(int) * (iSLen + 1));
//     pacStack[j] = -1;
//     i = 0;

//     while(i < iSLen){
//         char cTemp = s[i];

//         if(cTemp == '('){
//             pacStack[++j] = i;
//         }
//         else{
//             if(j == 0){
//                 pacStack[j] = i;
//             }
//             else{
//                 iMaxValid = i - pacStack[--j];
//                 if(iMaxValid > iMaxParenthess){
//                     iMaxParenthess = iMaxValid;
//                 }       
//             }    
//         }
//         ++i;
//     }

//     iReturn = iMaxParenthess;

//     return iReturn;
// }


int longestValidParentheses(char * s){
    int iSLen = strlen(s);
    int iMaxValid = 0;
    int iMaxParenthess = 0;
    int i = 0, j = 0;
    int iReturn = 0;
    int* pacStack = NULL; 

    if(iSLen < 2){
        return iReturn;
    }

    pacStack = (int*)malloc(sizeof(int) * (iSLen + 1));
    for(i = 0; i < iSLen; ++i){
        pacStack[i] = 0;
    };

    for(i = 0; i < iSLen; ++i){
         if(s[i] == '('){
            pacStack[i] = 0;
        }
        else{
            if(i - 1 >= 0 && s[i - 1] == '('){
                pacStack[i] = ((i > 2) ? pacStack[i - 2] : 0) + 2;
            }
            else{
                if(i >= 1 && i - pacStack[i - 1] > 0 && s[i - pacStack[i - 1] - 1] == '('){
                    pacStack[i] = pacStack[i - 1] + ((i - pacStack[i -  1] >= 2) ? pacStack[i - pacStack[i - 1] - 2] : 0) + 2;
                }
            }
        }
        if(pacStack[i] > iMaxParenthess){
            iMaxParenthess = pacStack[i];
        }

    }

    iReturn = iMaxParenthess;
    free(pacStack);

    return iReturn;
}

int main(){
    char aiNum[] = "()(())";
    int iReturn = 0;

    iReturn = longestValidParentheses(aiNum);

    printf("%d\n", iReturn);

    return 0;
}
// @lc code=end

