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

// double recurrence(double dNum, int iPown){
//     if(iPown == 0){
//         return 1.0;
//     }
//     double dReturn = recurrence(dNum, iPown / 2); 
//     if(iPown % 2 == 1){
        
//         return dNum * dReturn * dReturn;
//     }
//     else{
//         return dReturn * dReturn;
//     }
// }

// double myPow(double x, int n){
//     double dReturn = 1.0;
//     double dNum = 0.0;
//     int iPow = 0;

//     if(n == 0){
//         return 1.0;
//     }
//     if(x == 0){
//         return 0.0;
//     }
//     else if(x == 1){
//         return 1;
//     }
//     else if(x == -1){
//         if(n % 2){
//             return -1.0;            
//         }
//         else{
//             return 1.0;
//         }
        
//     }
//     if(n < 0){
//         dNum = (1 / x);
//         if(n == -2147483648){
//             dReturn = dNum;
//             iPow = -(n + 1);
//         }  
//         else
//         {
//             iPow = -n;
//         }
//     }
//     else{
//         dNum = x;
//         iPow = n;
//    }

//     dReturn *= recurrence(dNum, iPow);

//     return dReturn;
// }

double interation(double dNum, int iPown){
      double dReturn = 1.0;
      double dTemp = dNum;

      while (iPown > 0){
          if(iPown % 2 == 1){
              dReturn *= dTemp;
          }
          dTemp *= dTemp;
          iPown /= 2;
      }

      return dReturn;      
}

double myPow(double x, int n){
    double dReturn = 1.0;
    double dNum = 0.0;
    int iPow = 0;

    if(n == 0){
        return 1.0;
    }
    if(x == 0){
        return 0.0;
    }
    else if(x == 1){
        return 1;
    }
    else if(x == -1){
        if(n % 2){
            return -1.0;            
        }
        else{
            return 1.0;
        }
        
    }
    if(n < 0){
        dNum = (1 / x);
        if(n == -2147483648){
            dReturn = dNum;
            iPow = -(n + 1);
        }  
        else
        {
            iPow = -n;
        }
    }
    else{
        dNum = x;
        iPow = n;
   }

    dReturn *= interation(dNum, iPow);

    return dReturn;
}



int main(){
    double dReturn = 0;
    double dNum = 2;
    int iPow = -2147483648;
    //  int iPow = 10;


    dReturn = myPow(dNum, iPow);

    printf("%lf\n", dReturn);

    return 0;
}
// @lc code=end

