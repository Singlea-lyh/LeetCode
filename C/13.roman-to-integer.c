/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (54.66%)
 * Likes:    1898
 * Dislikes: 3294
 * Total Accepted:    618.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// int romanToInt(char * s){
//     int iSNum = 0;
//     int iReturn = 0;

//     iSNum = strlen(s);

//     for(int i = 0; i < iSNum; ++i){
//         if(s[i] == 'I'){
//             iReturn = (s[i+1] == 'V' || s[i+1] == 'X') ? iReturn - 1 : iReturn + 1;
//         }
//         else if(s[i] == 'V'){
//             iReturn += 5;
//         }
//         else if(s[i] == 'X'){
//             iReturn = (s[i+1] == 'L' || s[i+1] == 'C') ? iReturn - 10 : iReturn + 10;
//         }
//         else if(s[i] == 'L'){
//             iReturn += 50;
//         }
//         else if(s[i] == 'C'){
//             iReturn = (s[i+1] == 'D' || s[i+1] == 'M') ? iReturn - 100 : iReturn + 100;
//         }
//         else if(s[i] == 'D'){
//             iReturn += 500;
//         }
//         else if(s[i] == 'M'){
//             iReturn += 1000;
//         }
//     }

//     return iReturn;
// }


int romanToInt(char * s){
    int iSNum = 0;
    int iReturn = 0;

    iSNum = strlen(s);

    for(int i = 0; i < iSNum; ++i){
        

    }

}

int main(){
    int iReturn = romanToInt("LVIII");

    printf("%d\n", iReturn);

    return 0;
}


// @lc code=end

