/*
 * @lc app=leetcode id=30 lang=c
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.87%)
 * Likes:    763
 * Dislikes: 1154
 * Total Accepted:    167.4K
 * Total Submissions: 671.3K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
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

typedef unsigned int uint32_t; 

// int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
//     int* piReturn = NULL;
//     int iReturn = 0;
//     int iIndex = -1;
//     char* pWords = NULL;
//     char* pWordsTemp = NULL;
//     char* pWordsTemp1 = NULL;
//     int iSLocal = 0;
//     int iWordLocal = 0;
//     int* piWordSig = NULL;
//     char* pTempWord = NULL;
//     int iWordSig = 0;
//     int iWordCount = 0;
//     int iSLen = 0;
//     int iLocal = 0;

//     iSLen = strlen(s);

//     if(wordsSize == 0 || iSLen == 0){
//         *returnSize = 0;
//         return piReturn;
//     }

//     iWordCount = strlen(words[0]);

//     if(iSLen < (iWordCount * wordsSize)){
//         *returnSize = 0;
//         return piReturn;
//     }
//     pWords = (char*)malloc(sizeof(char) * (iWordCount * wordsSize + 1));
//     pWordsTemp = (char*)malloc(sizeof(char) * (iWordCount * wordsSize + 1));
//     pWordsTemp1 = (char*)malloc(sizeof(char) * (iWordCount * wordsSize + 1));
//     memset(pWords, 0, (iWordCount * wordsSize + 1));
//     memset(pWordsTemp, 0, (iWordCount * wordsSize + 1));
//     memset(pWordsTemp1, 0, (iWordCount * wordsSize + 1));


//     pTempWord = (char*)malloc(sizeof(char) * (iWordCount));

//     piReturn = (int*)malloc(sizeof(int) * iSLen);

//     piWordSig = (int*)malloc(sizeof(int) * wordsSize);
//     for(int i = 0; i < wordsSize; ++i){
//         piWordSig[i] = 0;
//     }
//     for(int i = 0; i < wordsSize; ++i){
//         strcat(pWords, words[i]);
//     }
//     memcpy(pWordsTemp, pWords, (iWordCount * wordsSize));
//     pWords[iWordCount * wordsSize] = '\0';
//     pWordsTemp[iWordCount * wordsSize] = '\0';

//     printf("%s\n", pWords);

//     while(iSLocal < iSLen){
//         memset(pTempWord, 0, iWordCount);
//         memcpy(pTempWord, s + iSLocal, iWordCount);
//         pTempWord[iWordCount] = '\0';

//         char *pLocal = strstr(pWordsTemp, pTempWord) ;

//         if( pLocal != NULL){
//             iWordLocal = (pLocal - pWordsTemp) / iWordCount;
//             if(piWordSig[iWordLocal + iLocal] == 0){
//                 piWordSig[iWordLocal + iLocal] = 1;
//                 ++iWordSig;
//                 if(iIndex == -1){
//                     iIndex = iSLocal;
//                 }
//                 if(iWordLocal == 0){
//                     memset(pWordsTemp1, 0, (iWordCount * wordsSize + 1));
//                     memcpy(pWordsTemp1, pWordsTemp + iWordCount, (wordsSize - iWordSig) * iWordCount);
//                     pWordsTemp1[(wordsSize - iWordSig) * iWordCount] = '\0';
//                 }
//                 else if(iWordLocal == (wordsSize - iWordSig)){
//                     memset(pWordsTemp1, 0, (iWordCount * wordsSize + 1));
//                     memcpy(pWordsTemp1, pWordsTemp, (wordsSize - iWordSig) * iWordCount);
//                     pWordsTemp1[(wordsSize - iWordSig) * iWordCount] = '\0';
//                 }
//                 else{
//                     memset(pWordsTemp1, 0, (iWordCount * wordsSize + 1));
//                     pTempWord[iWordLocal * iWordCount] = '\0';
//                     sprintf(pWordsTemp1, "%s", pWordsTemp);
//                     strcat(pWordsTemp1, pWordsTemp + (iWordLocal + 1) * iWordCount);
//                     pWordsTemp1[(wordsSize - iWordSig) * iWordCount] = '\0';
//                 }
//                 memcpy(pWordsTemp, pWordsTemp1, (wordsSize - iWordSig) * iWordCount);
//                 pWordsTemp[(wordsSize - iWordSig) * iWordCount] = '\0';

//                 // if(iSLocal < iIndex){
//                 //     iIndex = iSLocal;
//                 // }
//                 if(iWordSig == wordsSize){
//                     piReturn[iReturn++] = iIndex;
//                     iIndex = -1;
//                     iLocal = 0;
//                     for(int i = 0; i < wordsSize; ++i){
//                         piWordSig[i] = 0;
//                     }
//                     memcpy(pWordsTemp, pWords, (iWordCount * wordsSize));
//                     pWordsTemp[iWordCount * wordsSize] = '\0';
//                 }
//             }
//             else{
//                 iIndex = -1;
//                 iWordSig = 0;
//                 iLocal = 0;
//                 for(int i = 0; i < wordsSize; ++i){
//                     piWordSig[i] = 0;
//                 }
//                 memcpy(pWordsTemp, pWords, (iWordCount * wordsSize));
//                 pWordsTemp[iWordCount * wordsSize] = '\0';
//                 continue;
//             }
//         }
//         else{
//             iIndex = -1;
//             iWordSig = 0;
//             iLocal = 0;
//             for(int i = 0; i < wordsSize; ++i){
//                 piWordSig[i] = 0;
//             }
//             memcpy(pWordsTemp, pWords, (iWordCount * wordsSize));
//             pWordsTemp[iWordCount * wordsSize] = '\0';
//         }
//         if(iIndex == -1){
//             ++iSLocal;
//         }
//         else{
//             iSLocal += iWordCount;
//         }
        
//         if((iSLen - iSLocal) < (iWordCount * wordsSize)){
//             break;
//         }
//     }

//     *returnSize =  iReturn;
//     return piReturn;
// }


uint32_t simple_hash(char *s, int len)
{
    uint32_t ret = 0;
    for (int i = 0; i < len; i++)
    {
        char shift = i % 4;
        ret += (*(s + i) << shift * 8);
    }

    return ret;
}

int isContactSubstr(uint32_t *pow_s_hash, uint32_t add_words_hash, int wordsSize, int word_len)
{
    uint32_t add_s_hash = 0;

    for (int i = 0; i < wordsSize; i++)
    {
        add_s_hash += pow_s_hash[i * word_len];
    }

    return add_words_hash == add_s_hash;
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    *returnSize = 0;
    int *results = (int *)malloc(sizeof(int) * 0xFF);

    if (!wordsSize || !s[0])
    {
        return results;
    }

    int word_len = strlen(words[0]);
    int substr_len = wordsSize * word_len;

    uint32_t pow_s_hash[0xFFFF];
    uint32_t add_words_hash = 0;

    int s_len = strlen(s);

    for (int i = 0; i <= s_len - word_len; i++)
    {
        uint32_t hash  = simple_hash(s + i, word_len);
        pow_s_hash[i] = hash * hash;
    }

    for (int i = 0; i < wordsSize; i++)
    {
        uint32_t hash = simple_hash(words[i], word_len);
        add_words_hash += hash * hash;
    }

    for (int i = 0; i <= s_len - substr_len; i++)
    {
        if (isContactSubstr(pow_s_hash + i, add_words_hash, wordsSize, word_len))
        {
            results[(*returnSize)++] = i;
        }
    }

    return results;
}

int main(){
    // char acSource[] = "wordgoodgoodgoodbestword";
    // int iWordsSize = 4;
    // int iWordCount = 4;

    char acSource[] = "barfoothefoobarman";
    int iWordsSize = 2;
    int iWordCount = 3;

    int iReturnSize = 0;
    int* paiReturn = NULL;
    char** ppacWords = (char**)malloc(sizeof(char*) * iWordsSize);

    for(int i = 0; i < iWordsSize; ++i){
        ppacWords[i] = (char*)malloc(sizeof(char) * (iWordCount + 1));
    }

    // sprintf(ppacWords[0], "%s", "word");
    // sprintf(ppacWords[1], "%s", "good");
    // sprintf(ppacWords[2], "%s", "best");
    // sprintf(ppacWords[3], "%s", "word");

    sprintf(ppacWords[0], "%s", "foo");
    sprintf(ppacWords[1], "%s", "bar");

    paiReturn = findSubstring(acSource, ppacWords, iWordsSize, &iReturnSize);

    printf("[");
    for(int i = 0; i < iReturnSize; ++i){
        printf("%d, ", paiReturn[i]);
    }
    printf("]");
    printf("\n");

  
    free(paiReturn);
    

    return 0;
}


// @lc code=end

