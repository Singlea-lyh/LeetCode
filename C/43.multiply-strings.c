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
    int iMulLen = 0;
    char* pcReturn = NULL;
    char* pcReturnTemp = (char*) malloc(sizeof(char) * (iNumLen1 + iNumLen2 + 2));
    memset(pcReturnTemp, 0, sizeof(char) * (iNumLen1 + iNumLen2 + 1));

    pcReturn = (char*)malloc(sizeof(char) * (iNumLen1 + iNumLen2 + 2));
    memset(pcReturn, 0, sizeof(char) * (iNumLen1 + iNumLen2 + 1));

    if((iNumLen1 == 1 && num1[0] == '0') || (iNumLen2 == 1 && num2[0] == '0')){
        free(pcReturn);
        pcReturnTemp[0] = (char) ('0' + 0);
        return pcReturnTemp;
    }
    if(iNumLen1 == 1 && num1[0] == '1'){
        return num2;
    }
    else if(iNumLen2 == 1 && num2[0] == '1'){
        return num1;
    }

    for(int i = iNumLen2 - 1; i >= 0; --i){
        int iCarry = 0;
        int iBase = num2[i] - '0';
        int iLocal = 0;
        char* pcTemp = (char*)malloc(sizeof(char) * (iNumLen1 + iNumLen2 + 2));
        memset(pcTemp, 0, sizeof(char) * (iNumLen1 + iNumLen2 + 2));
        for(iLocal = 0; iLocal < (iNumLen2 - 1 - i); ++iLocal);

        for(int j = iNumLen1 - 1; j >= 0; --j){
            int iTemp = num1[j] - '0';
            int iMulTemp = (iBase * iTemp + iCarry) % 10;
            pcTemp[iLocal++] = (char)('0' + iMulTemp);
            iCarry = (iBase * iTemp + iCarry) / 10;
        }
        if(iCarry != 0){
            pcTemp[iLocal++] =  (char)('0' + iCarry);
        }

        int  iAddCarry = 0;
        for(int l = 0; l < iLocal; ++l){
            int iTemp = (pcTemp[l] == 0) ? 0 : (pcTemp[l] - '0');
            int iReturn = (pcReturn[l] == 0) ? 0 : (pcReturn[l] - '0');
            int iAddTemp = ( iTemp+  iReturn + iAddCarry) % 10;
            iAddCarry = (iTemp+  iReturn + iAddCarry) / 10;
            pcReturn[l] = (char)('0' + iAddTemp);
        }
        if(iAddCarry != 0){
            pcReturn[iLocal++] = (char)('0' + iAddCarry);
        }
        iMulLen = (iLocal > iMulLen) ? iLocal : iMulLen;
    }

    for(int i = 0; i < iMulLen; ++i){
        pcReturnTemp[i] = pcReturn[iMulLen - 1 - i];
    }
    free(pcReturn);

    return pcReturnTemp;
}

int main(){
    char* pcNum1 = "140";
    char* pcNum2 = "721";
    char* pcReturn = NULL;

    pcReturn = multiply(pcNum1, pcNum2);

    printf("%s\n", pcReturn);

    // free(pcReturn);

    return 0;
}
// @lc code=end

