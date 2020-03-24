/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.63%)
 * Likes:    2982
 * Dislikes: 4709
 * Total Accepted:    991.7K
 * Total Submissions: 3.9M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
#include <stdio.h>

#define MAX  2147483647
#define MIN  -2147483648

// #define MAX  0x7fffffff
// #define MIN  0x80000001

int reverse(int x){
    int iReturn = 0;
    int iTemp1 = 0, iTemp = 0;

    if(x == 0){
        return x;
    }
   
    iTemp = x;

    while(iTemp != 0){
        iTemp1 = iTemp % 10;
        iTemp /= 10;

        if(iReturn > MAX / 10 || (iReturn == MAX / 10) && iTemp1 > 7) return 0;
        if(iReturn < MIN / 10 || (iReturn == MIN / 10) && iTemp1 < -8) return 0;

        iReturn = iReturn * 10 + iTemp1;
    }

    return iReturn;
}

int main(){
    int x =123;

    int a = reverse(x);

    printf("%d\n", a);
}


// @lc code=end

