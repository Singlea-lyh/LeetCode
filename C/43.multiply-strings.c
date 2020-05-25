/*
 * @lc app=leetcode id=43 lang=c
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.89%)
 * Likes:    1634
 * Dislikes: 747
 * Total Accepted:    281.2K
 * Total Submissions: 844.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * multiply(char * num1, char * num2){
    int iNumLen1 = strlen(num1);
    int iNumLen2 = strlen(num2);

    if((iNumLen1 == 1 && num1[0] == '0') || (iNumLen2 == 1 && num2[0] == '0')){
        return 0;
    }
    if(iNumLen1 == 1 && num1[0] == '1'){
        return num2;
    }
    else if(iNumLen2 == 1 && num2[0] == '1'){
        return num1;
    }
    
    


}

int main(){
    char* pcNum1 = "2";
    char* pcNum2 = "3";
    char* pcReturn = NULL;

    pcReturn = multiply(pcNum1, pcNum2);

    printf("%s\n", pcReturn);

    free(pcReturn);

    return 0;
}
// @lc code=end

