/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (45.23%)
 * Likes:    3352
 * Dislikes: 378
 * Total Accepted:    550.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// char ** letterCombinations(char * digits, int* returnSize){
//     int iDigitNums = 0;
//     int* iDigit = NULL;
//     char** ppacLetter = NULL;
//     char** ppacReturn = NULL;

//     iDigitNums = strlen(digits);
//     *returnSize = 1;

//     if(iDigitNums == 0){
//         *returnSize = 0;
//         return NULL;
//     }

//     ppacLetter = (char**)malloc(sizeof(char*) * iDigitNums);
//     iDigit = (int*)malloc(sizeof(int) * iDigitNums);

//     for(int i = 0; i < iDigitNums; ++i){
//         iDigit[i] = digits[i] - '0';
//         if(iDigit[i] < 2 || iDigit[i] > 9){
//             *returnSize = 0;
//             return NULL;
//         }
//         if(iDigit[i] == 9 || iDigit[i] == 7){
//             *returnSize *= 4;
//             ppacLetter[i] = (char*)malloc(sizeof(char) * 4);
//             for(int j = 0; j < 4; ++j){
//                 ppacLetter[i][j] = (char)('a' + (iDigit[i] - 2) * 3 + j);
//             }

//         }
//         else{
//             *returnSize *= 3;
//             ppacLetter[i] = (char*)malloc(sizeof(char) * 3);
//             for(int j = 0; j < 3; ++j){
//                 ppacLetter[i][j] = (char)('a' + (iDigit[i] - 2) * 3 + j);
//             }
//         }
//     }

//     int iIntervl = *returnSize;

//     ppacReturn = (char**)malloc(sizeof(char) * (*returnSize));

//     for(int i = 0; i < *returnSize; ++i){
//         ppacReturn[i] = (char*)malloc(sizeof(char) * (iDigitNums + 1));
//         ppacReturn[i][iDigitNums] = "\0";
//     }

//     for(int i = 0; i < iDigitNums; ++i){
//         iIntervl /= ((iDigit[i] == 7 || iDigit[i] == 9) ? 4: 3);
//         for(int j = 0; j < *returnSize; ++j){
//             ppacReturn[j][i] = ppacLetter[i][j];
//         }
//     }

//     for(int i = 0; i < iDigitNums; ++i){
//         free(ppacLetter[i]);
//     }
//     free(ppacLetter);
//     free(iDigit);

//     return ppacReturn;
// }

int haopengyou(char c)
{
    if(c=='7') return 4;
    if(c=='9') return 4;
    return 3;
}
char ** letterCombinations(char * digits, int* returnSize){
    int l=strlen(digits),i,j,interval;
    char **ans,se[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(l==0)
    {
        *returnSize=0;
        return NULL;
    }
    *returnSize=1;
    for(i=0;i<l;i++) (*returnSize)*=haopengyou(digits[i]);
    ans=(char **)malloc((*returnSize)*sizeof(char *));
    interval=*returnSize;
    for(i=0;i<(*returnSize);++i)
    {
        *(ans+i)=(char *)malloc((l+1)*sizeof(char));
        ans[i][l]='\0';
    }
    for(i=0;i<l;++i)
    {
        interval/=haopengyou(digits[i]);
        for(j=0;j<(*returnSize);++j)
        {
            ans[j][i]=se[digits[i]-'2'][(j/interval)%haopengyou(digits[i])];
        }
    }
    return ans;
}

int main(){
    char pacDigits[] = "234";
    int iReturnSize = 1;
    char** ppacReturn = letterCombinations(pacDigits, &iReturnSize);

    printf("{ ");
    for(int i = 0; i < iReturnSize; ++i){
        printf("%s, " , ppacReturn[i]); 
        // printf("%s, " , *(ppacReturn + i));       
    }
    printf("}\n");

    for(int i = 0; i < iReturnSize; ++i){
        free(ppacReturn[i]);
    }

    return 0;
}


// @lc code=end



