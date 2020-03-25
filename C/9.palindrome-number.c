/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (46.87%)
 * Likes:    2012
 * Dislikes: 1495
 * Total Accepted:    834.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
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

// bool isPalindrome(int x){
//     bool bIsPad = true;
//     int iNum = 0;
//     int iTemp = x;
//     int iCount = 0;
//     int iStart = 1, iEnd = 0;

//     if(iTemp < 0){
//         return false;
//     }
//     else if(iTemp >= 0 && iTemp <= 9){
//         return true;
//     }

//     while(iTemp > 0){
//         iTemp /= 10;
//         iNum++;
//     }

//     iEnd = iNum;
//     iCount = iNum;
//     iTemp = x;

//     while(iCount > 1){
//         int iNum1 = iNum - iCount;
//         iStart = iTemp % 10;
//         iEnd = x / (int)(pow(10, iNum  - 1 - iNum1 / 2));
//         iEnd %= 10;

//         if(iStart != iEnd){
//             bIsPad = false;
//             break;
//         }
//         else{
//             iTemp /= 10;
//             iCount -= 2;
//         }
//     }

//     return bIsPad;   

// }

bool isPalindrome(int x){
    bool bIsPad = false;
    int iReverteNum = 0;
    int iTemp = x;

    if(x < 0 || (x % 10  == 0 && x != 0)){
        return false;
    }

    while(iReverteNum < iTemp){
        iReverteNum = iReverteNum * 10 + iTemp % 10;
        iTemp /= 10;
    }

    if(iReverteNum == iTemp || (iReverteNum / 10) == iTemp){
        bIsPad = true;
    }

    return bIsPad;
}

int main(){
    int x = 121;
    bool iReturn = isPalindrome(x);

    int iReturn1 = (iReturn) ? 1 : 0;
    

    printf("%d\n", iReturn1);

    return 0;    
}


// @lc code=end

