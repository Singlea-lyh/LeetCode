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
/*
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

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
*/

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

int palindromeLen(char* s, int iSLen, int iMid, int iLastLen){
    int iReturn  = 0;
    int iL = iMid - iLastLen;
    int iR = iMid + iLastLen;

    while(iL >= 0 && iR < iSLen && s[iL] == s[iR]){
        --iL;
        ++iR;
        ++iLastLen;
    }

    iReturn = iLastLen;

    return iReturn;
}

char *longestPalindrome(char *s){
    int iSumLen = strlen(s);
    int iTemp = iSumLen * 2 + 1;
    int iStart=0, iEnd = 0;
    int iMaxLen = 0;
    int iPox = 0, iMaxRight = 0;
    char *acReturn = NULL ;
    int *iRL = NULL;
    char *asTemp = NULL;

    if(iSumLen == 0){
        return "";
    }

    acReturn = (char*)malloc(sizeof(char) * (iSumLen + 1));
    iRL = (int *)malloc(sizeof(int) * iTemp);
    asTemp = (char*)malloc(sizeof(char) * iTemp);

    for(int i = 0, j = 0 ; i < iSumLen; ++i, ++j){
        asTemp[j++] = '#';
        asTemp[j] = s[i];
    }
    asTemp[iTemp - 1] = '#';

    for(int i = 0; i < iSumLen * 2 + 1; ++i){
        int iLastLen = 0;

        if(i < iMaxRight){
            iLastLen = MIN(iRL[2 * iPox - i], iMaxRight - i);
        }
        else{
            iLastLen = 1;
        }

        iRL[i] = palindromeLen(asTemp, iTemp, i, iLastLen);

        if(iRL[i] + i - 1 > iMaxRight){
            iMaxRight = iRL[i] + i - 1;
            iPox = i;
        }
    }

    for(int i = 0; i < iTemp; ++i){
        if((iRL[i] - 1) > iMaxLen){
            iMaxLen = iRL[i] - 1;
            iStart = i - (iRL[i] - 1);
            printf("%d -- %d\n", iMaxLen, iStart);       
        }
    }

    // memset(acReturn, 0, (sizeof(char) * (iSumLen + 1)));
   

    int j = 0;
    int i = iStart;
    memset(acReturn, 0, iSumLen + 1);
    while(j < iMaxLen && i < iTemp){
        if(asTemp[i] == '#'){
            ++i;
        }
       acReturn[j++] = asTemp[i++];
    }

    free(iRL);
    free(asTemp);

    return acReturn;
}

int main(){
    char s[] = "babad";

    // char d[10];s
    // memcpy(d, s, 2);
    // printf("%s\n", d);

    printf("%s\n", longestPalindrome(s));

    return 0;
}

// @lc code=end

