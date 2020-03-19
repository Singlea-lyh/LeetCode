/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.82%)
 * Likes:    5734
 * Dislikes: 480
 * Total Accepted:    827.7K
 * Total Submissions: 2.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
/*
char * longestPalindrome(char * s){
    char *acMaxPalindromic = (char*)malloc(sizeof(char) * MAX_LEN);
    int iLen = 0, iStringLen =0;
    int iMaxLen = 0;
    int aiPalindrom[MAX_LEN][MAX_LEN] = {0};

    iStringLen = strlen(s);

    if(iStringLen == 0){
        return "";
    }
    
    for(iLen = 1; iLen <= iStringLen; ++iLen){
        for(int iStart = 0; iStart < iStringLen; ++iStart){
            int iEnd = iStart + iLen - 1;

            if(iEnd < iStart){
                break;
            }

            if(iLen == 1){
                aiPalindrom[iStart][iEnd] = 1;
            }
            else if(iLen == 2){
                if(s[iStart] == s[iEnd]){
                    aiPalindrom[iStart][iEnd] = 1;
                }
            }
            else if(aiPalindrom[iStart + 1][iEnd - 1]){
                if(s[iStart] == s[iEnd]){
                    aiPalindrom[iStart][iEnd] = 1;
                }
            }
            if(aiPalindrom[iStart][iEnd] && iLen > iMaxLen){
                iMaxLen = iLen;
                memset(acMaxPalindromic, 0, MAX_LEN);
                memcpy(acMaxPalindromic, s + iStart, iLen);
            }
        }
    }

    return acMaxPalindromic;
}
*/
#define MAX(a, b) (a > b) ? a : b

int palindromeLen(char* s, int iSLen, int iLeft, int iRight){
    int iReturn  = 0;
    int iL = iLeft, iR = iRight;

    while(iL >= 0 && iR < iSLen && s[iL] == s[iR]){
        --iL;
        ++iR;
    }

    iReturn = iR - iL - 1;

    return iReturn;
}


char * longestPalindrome(char * s){
    char *acMaxPalindromic = (char*)malloc(sizeof(char) * MAX_LEN);
    int iStringLen = 0;
    int iMaxLen = 0;
    int iLen1 = 0, iLen2 = 0, iLen = 0;
    int i = 0;
    int iStart ,iEnd;

    iStart = iEnd = 0;

    iStringLen = strlen(s);

    if(iStringLen == 0){
        return "";
    }

    for(i = 0; i <= iStringLen; ++i){
        iLen1 = palindromeLen(s, iStringLen,  i, i);
        iLen2 = palindromeLen(s,  iStringLen, i, i + 1);

        iLen = MAX(iLen1, iLen2);

        if(iLen > iMaxLen){
            iStart = i - (iLen - 1) / 2;
            iEnd = i + iLen / 2;
            iMaxLen = iLen;
        }   
    }

    memset(acMaxPalindromic, 0, MAX_LEN);

    memcpy(acMaxPalindromic, s + iStart, iMaxLen);

    return acMaxPalindromic;    
}


int main(){
    char s[] = "babad";

    // char d[10];

    // memcpy(d, s, 2);
    // printf("%s\n", d);

    printf("%s\n", longestPalindrome(s));

    return 0;
}

// @lc code=end

