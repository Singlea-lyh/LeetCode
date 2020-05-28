/*
 * @lc app=leetcode id=44 lang=c
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (24.16%)
 * Likes:    1819
 * Dislikes: 101
 * Total Accepted:    236K
 * Total Submissions: 968.3K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int bool;
#define false 0
#define true 1

// bool isMatch(char * s, char * p){
//     bool bIsReturn = false;
//     int iSlen = strlen(s);
//     int iPatternLen = strlen(p);
//     bool** ppPattern = NULL;

//     ppPattern = (bool**)malloc(sizeof(bool*) * (iSlen + 1));
//     for(int i = 0; i <= iSlen; ++i){
//         ppPattern[i] = (bool*)malloc(sizeof(bool) * (iPatternLen + 1));
//     }

//     for(int i = 0; i <= iSlen; ++i){
//         for(int j = 0; j <= iPatternLen; ++j){
//             ppPattern[i][j] = false;
//         }
//     }

//      ppPattern[0][0] = true;

//     for(int i = 1; i <= iPatternLen; ++i){
//         ppPattern[0][i] = (ppPattern[0][i - 1] && (p[i - 1] == '*'));
//     }

//     for(int i = 1; i <= iSlen; ++i){
//         for(int j = 1; j <= iPatternLen; ++j){
//             if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
//                 ppPattern[i][j] = ppPattern[i - 1][j - 1];
//             }
//             else if(p[j - 1] == '*'){
//                 ppPattern[i][j] = ppPattern[i][j - 1] || ppPattern[i - 1][j];
//             }
//         }
//     }

//     // for(int i = 0; i <= iSlen; ++i){
//     //     for(int j = 0; j <= iPatternLen; ++j){
//     //         printf("%d, ", ppPattern[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     bIsReturn = ppPattern[iSlen][iPatternLen];
//     for(int i = 0; i < iSlen; ++i){
//         free(ppPattern[i]);
//     }
//     free(ppPattern);

//     return bIsReturn;  
// }

bool isMatch(char * s, char * p){
    bool bIsReturn = false;
    int iSlen = strlen(s);
    int iPatternLen = strlen(p);
    int iSStar = -1, iPStar = -1;
    int i = 0, j = 0;
    while(i < iSlen){
        if(j < iPatternLen && s[i] == p[j] || p[j] == '?'){
            ++i;
            ++j;
        }
        else if(j < iPatternLen && p[j] == '*'){
            iSStar = i;
            iPStar = j++;
        }
        else if(iSStar >= 0){
            i = ++iSStar;
            j = iPStar + 1;
        }
        else{
            return false;
        }
    } 
    while(j < iPatternLen && p[j] == '*') ++j;

    return (j == iPatternLen);  
}

int main(){
    bool bIsMatch = false;
    char* pcSource = "";
    char* pcPattern = "*";

    bIsMatch = isMatch(pcSource, pcPattern);

    if(bIsMatch){
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}
// @lc code=end

