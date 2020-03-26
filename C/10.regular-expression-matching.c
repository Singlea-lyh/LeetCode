/*
 * @lc app=leetcode id=10 lang=c
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (26.24%)
 * Likes:    3689
 * Dislikes: 644
 * Total Accepted:    395.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
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
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0


// bool isMatch(char * s, char * p){
//     int iStrLen = 0;
//     int iPatternLen = 0;
//     int iStr = 0, iPat = 0;
    
//     iStrLen = strlen(s);
//     iPatternLen = strlen(p);

//     if(iStrLen == 0 || iPatternLen == 0){
//         return false;
//     }


//     int i = 0, j = 0;

//     while(i < iPatternLen && j < iStrLen){
//         char cPatTemp = p[i];
//         char cStrTemp = s[j];

//         if(cStrTemp < 'a' || cStrTemp > 'z'){
//             return false;
//         }

//         if((cPatTemp < 'a' || cPatTemp > 'z') && (cPatTemp != '.' && cPatTemp != '*')){
//             return false;
//         }

//         if(cPatTemp == '.'){
//             ++i;
//             ++j;
//         }
//         else if(cPatTemp == '*'){
//             char cStr[] = "aaa";
//             char cPattern[] = "aa*c*c*a";
//             if(j + 1 < iStrLen && i + 1 < iPatternLen && s[j + 1] != p[i + 1]){
//                 if((p[i - 1] == '.' || p[i - 1] == cStrTemp) && s[j + 1] == cStrTemp){
//                     ++j;
//                 }
//                 else if((p[i - 1] == '.' || p[i - 1] == cStrTemp) && s[j + 1] != cStrTemp){
//                     ++i;
//                     ++j;
//                 }      
//                 else{
//                     return false;
//                 }
//             }
//             else if(j + 1 < iStrLen && i + 1 < iPatternLen && s[j + 1] == p[i + 1]){
//                 if(p[i - 1] == '.' || p[i - 1] == cStrTemp){
//                     ++j;
//                     ++i;
//                 }      
//                 else{
//                     return false;
//                 }
//             }
//             else if(i + 1 < iPatternLen && cStrTemp == p[i+1]){
//                 i += 2;
//                 ++j;
//             }
//             else{
//                 if(i + 2 < iPatternLen && p[i + 2] == '*'){
//                     if(i + 3 < iPatternLen && p[i + 3] == cStrTemp){
//                         i = i +4;
//                         ++j;
//                     }
//                     else{
//                         i += 2;
//                     }

//                 } 
//                 else if(p[i - 1] == '.' || p[i - 1] == cStrTemp){
//                     ++j;
//                 }     
//                 else{
//                     return false;
//                 }
//             }
//         }
//         else if(cPatTemp == cStrTemp){
//             ++i;
//             ++j;
//         }
//         else if(cPatTemp != cStrTemp){
//             if(p[i + 1] == '*'){
//                 i += 2;
//             }
//             else{
//                 return false;       
//             }    
//         }
//         else{
//             return false;
//         }
//     }
    
//     if(i < iPatternLen - 1 && j <= iStrLen){
//         return false;
//     }
//     else if(j == iStrLen){
//         if((i == iPatternLen - 1 && p[i] == '*') || (iPatternLen == i && p[i - 1] != '*')){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     else{
//         return false;
//     }
    
//     return false;
// }

bool isMatch(char * s, char * p){
    if (!*p) return !*s;
    bool bIsFirstMatch = *s && (*s == *p || *p == '.');
    if (*(p+1) == '*') {
        return isMatch(s, p+2) || (bIsFirstMatch && isMatch(++s, p));
    }
    else {
        return bIsFirstMatch && isMatch(++s, ++p);
    }
}

int main(){
    char cStr[] = "aaca";
    char cPattern[] = "ab*a*c*a";

    bool bIsReturn = isMatch(cStr, cPattern);

    int iReturn1 = (bIsReturn) ? 1 : 0;
    

    printf("%d\n", iReturn1);

    return 0;    
}


// @lc code=end

