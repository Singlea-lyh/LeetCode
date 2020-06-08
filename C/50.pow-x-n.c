/*
 * @lc app=leetcode id=50 lang=c
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (29.19%)
 * Likes:    1401
 * Dislikes: 2924
 * Total Accepted:    452.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double myPow(double x, int n){

}

int main(){
    double dReturn = 0;
    double dNum = 2;
    int iPow = 10;

    dReturn = myPow(dNum, iPow);

    printf("%lf\n", dReturn);

    return 0;
}
// @lc code=end

