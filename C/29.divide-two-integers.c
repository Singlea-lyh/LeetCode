/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.17%)
 * Likes:    1027
 * Dislikes: 4811
 * Total Accepted:    258.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int townumdivide(int iDividend, int iDivisor){
    int iTemp = 0;
    int iCount = 0;
    if(iDividend < iDivisor){
        return 0;
    }

    if((iDivisor >= (2147483646 >> 2))){
        return (1 + townumdivide(iDividend - iDivisor, iDivisor));
    }

    iTemp = iDivisor;
    iCount = 1;
    while(iTemp + iTemp < iDividend){
        iCount += iCount;
        iTemp += iTemp;
        if((iTemp >= (2147483646 >> 2))){
            break;
        }
    }

    return (iCount + townumdivide(iDividend - iTemp, iDivisor));
}

int divide(int dividend, int divisor){
    int iReturn = 0;
    int iSign = 1;
    int iDividendTemp = dividend;
    int iDivisorTemp = divisor;

    if(dividend >  2147483647){
        return 2147483647;
    }
    if(dividend < -2147483648){
        return -2147483648;
    }
    if(dividend == 0){
        return 0;
    }
    if(divisor == 1){
        return dividend;
    }
    if(divisor == -1){
        if(dividend != -2147483648){
            return -dividend;
        }
        else{
            return 2147483647;
        }
        
    }
    if(divisor == -2147483648 && dividend == -2147483648){
        return 1;
    }
    if(divisor == -2147483648){
        return 0;
    }


    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
        iSign = -1;
    }

    if(dividend == -2147483648 && iSign == -1){
        iDividendTemp += iDivisorTemp;
        iReturn++;
    }
    else if(dividend == -2147483648 && iSign == 1){
        iDividendTemp -= iDivisorTemp;
        iReturn++;
    }
    
    if(iDividendTemp < 0){
        iDividendTemp = -iDividendTemp;
    }
    if(iDivisorTemp < 0){
        iDivisorTemp = -iDivisorTemp;
    }


    iReturn += townumdivide(iDividendTemp, iDivisorTemp);

    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
        iReturn = -iReturn;
    }

    return iReturn;
}

int main(){
    int iDividend = -2147483648;
    int iDivisor = 2;

    int iReturn = divide(iDividend, iDivisor);

    printf("%d\n", iReturn);

    return 0;
}


// @lc code=end

