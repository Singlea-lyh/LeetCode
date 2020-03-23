/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (34.90%)
 * Likes:    1448
 * Dislikes: 4173
 * Total Accepted:    420.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
char * convert(char * s, int numRows){
    int iStrLen = 0;
    char *acConvertStr = NULL;
    int iDistance = 0;
    int iReturn = 0;

    iStrLen = strlen(s);

    if(numRows <= 1){
        return s;
    }

    iDistance = 2 * (numRows - 1);

    acConvertStr = (char*)malloc(sizeof(char) * (iStrLen + 1));

    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < iStrLen; ++j){
            int k = j % iDistance;
            if(i == k || k == iDistance - i){
                acConvertStr[iReturn++] = s[j];
            }
        }
    }

    acConvertStr[iStrLen] = '\0';

    return acConvertStr;
}
*/

char * convert(char * s, int numRows){
    int iStrLen = 0;
    char *acConvertStr = NULL;
    int iDistance = 0;
    int iReturn = 0;

    iStrLen = strlen(s);
    iDistance = 2 * (numRows - 1);

    if(numRows <= 1){
        return s;
    }

    acConvertStr = (char*)malloc(sizeof(char) * (iStrLen + 1));

    for(int i = 0; i < numRows; ++i){
         int j = i;
         int iAdd = i * 2;
      
        while(j < iStrLen){
            acConvertStr[iReturn++] = s[j];
            iAdd = iDistance - iAdd;
            j += (i == 0 || i == numRows - 1) ? iDistance : iAdd;
        }
        
    }

    acConvertStr[iStrLen] = '\0';

    return acConvertStr;
}

int main(){
    char s[] = "PAYPALISHIRING";

    printf("%s\n", convert(s, 4));
}


// @lc code=end

