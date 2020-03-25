/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (15.06%)
 * Likes:    1360
 * Dislikes: 8226
 * Total Accepted:    501.6K
 * Total Submissions: 3.3M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */

// @lc code=start

// #define MAX 0x7fffffff
// #define MIN 0x80000000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX  2147483647
#define MIN  -2147483648

int myAtoi(char * str){
    int iStrLen = 0;
    int iReturn = 0;
    int iIsPlus = -1;
    int i = 0;
    int iStart = 0;

    iStrLen = strlen(str);

    if(iStrLen == 0){
        return iReturn;
    }

    while(i < iStrLen){
        char cTemp = str[i];
        if(cTemp == '-' ){
            if(iReturn == 0 && iIsPlus == -1 && iStart == 0) {
                iIsPlus = 0;
                iStart = 1;
            }
            else{
                break;
            } 
        }
        else if(cTemp == '+' && iIsPlus == -1 && iStart == 0){
             if(iReturn == 0) {
                iIsPlus = 1;
                iStart = 1;
            }
            else{
                break;
            } 
        }
        else if(cTemp >= '0' && cTemp <= '9'){
            if(iReturn > MAX || (iReturn == MAX / 10 && (cTemp - '0') > 7) || iReturn > MAX / 10) return MAX;
            if(iReturn < MIN || (iReturn == MIN / 10 && ('0' - cTemp) < -8) || iReturn < MIN / 10) return MIN;
            iReturn = (iIsPlus) ? (iReturn * 10 + (cTemp - '0')) : (iReturn * 10 + ('0' - cTemp));
            iStart = 1;
        }
        else if((cTemp >= 'a' && cTemp <= 'z') || (cTemp >= 'A' && cTemp <= 'Z')){
            if(iReturn != 0){
                break;
            }
            else{
                return iReturn;   
            }    
        }
        else if(cTemp == ' '){
            if(iReturn != 0 || (iReturn == 0 && iStart)){
                break;
            }
        }
        else{
            if(iReturn != 0){
                break;
            }
            else{
                return 0;
            }
        }
        
        ++i;      
    }
    return iReturn;
}

int main(){
    char str[] = "0-1";

    printf("%d\n", myAtoi(str));
}


// @lc code=end

