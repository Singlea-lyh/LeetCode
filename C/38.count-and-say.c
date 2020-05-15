/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (43.40%)
 * Likes:    1198
 * Dislikes: 9065
 * Total Accepted:    381.4K
 * Total Submissions: 870.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence. You can do so recursively, in other words from the
 * previous member read off the digits, counting the number of digits in groups
 * of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two groups "2" and
 * "1", "2" can be read as "12" which means frequency = 1 and value = 2, the
 * same way "1" is read as "11", so the answer is the concatenation of "12" and
 * "11" which is "1211".
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 5120

char* recurrence(int iN){
    int iSLen = 0;
    char* pcReturn = (char*)malloc(sizeof(char) * MAX_LEN);
    char* pcPreReturn = NULL;
    int i = 0, j = 0;
    int iLocal = 0;
    
    if(iN == 1){
        pcReturn[0] = '1';
        pcReturn[1] = '\0';
        return pcReturn;
    }
    pcPreReturn = recurrence(iN - 1);

    iSLen = strlen(pcPreReturn);

    while(i < iSLen){
        int iCount = 0;
        char cBase = pcPreReturn[i++];
        iCount = 1;
        while(i < iSLen && pcPreReturn[i] == cBase){
            ++iCount;
            ++i;    
        }
        pcReturn[iLocal++] = (char)('0' + iCount);
        pcReturn[iLocal++] = cBase;         
    }
    pcReturn[iLocal] = '\0';
    
    free(pcPreReturn);

    return pcReturn;
}

char * countAndSay(int n){
    char* pcReturn = NULL;
    
    if(n < 1 || n > 30){
        return NULL;
    }

    pcReturn = recurrence(n);

    return pcReturn;
}

int main(){
    char *pcReturn = NULL;
    int iNum = 28;

    pcReturn = countAndSay(iNum);

    printf("%s\n", pcReturn);

    free(pcReturn);

    return 0;   
}


// @lc code=end

