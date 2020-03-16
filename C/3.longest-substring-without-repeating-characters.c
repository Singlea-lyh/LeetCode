/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.65%)
 * Likes:    8008
 * Dislikes: 490
 * Total Accepted:    1.4M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
     char* cFront;
    char* cRear;   
    int iLen = 0;
    char cChar[128] = {0};
    int iMaxLen = 0, iSize = 0;

    iLen = strlen(s);

    cFront = cRear = s;

    if(iLen == 0 || iLen == 1){
        return iLen;
    }

    while(cRear < s + iLen){

        if(!cChar[*cRear]){
            cChar[*cRear] = 1;
            iSize++;
            ++cRear;
        }
        else{
            if(iMaxLen < iSize){
                iMaxLen = iSize;
            }
            while(*cFront != *cRear){
                cChar[*cFront] = 0;
                cFront++;
                iSize--;
            }
            cFront++;
            cRear++;
        }
    }

    if(iMaxLen < iSize){
        iMaxLen = iSize;
    }

    return iMaxLen;
}


// @lc code=end

