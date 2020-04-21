/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.92%)
 * Likes:    1379
 * Dislikes: 1757
 * Total Accepted:    613.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int strStr(char * haystack, char * needle){
    int iHayStackLen = strlen(haystack); 
    int iNeedleLen = strlen(needle);
    int i = 0;
    
    if(iHayStackLen < iNeedleLen){
        return -1;
    }

    while(i <= iHayStackLen - iNeedleLen){
        if(memcmp(haystack + i, needle, iNeedleLen) == 0){
            break;
        }
        ++i;
    }

    if(i <= iHayStackLen - iNeedleLen){
        return i;

    }
    else{
        return -1;
    }
}

int main(){
    char acHayStack[] = "hello";
    char acNeedle[] = "hh";

    int iReturn = 0;

    iReturn = strStr(acHayStack, acNeedle);

    printf("%d\n", iReturn);

    return 0;
}


// @lc code=end

