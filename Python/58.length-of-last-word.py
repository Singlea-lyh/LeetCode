#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#
# https://leetcode.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (32.47%)
# Likes:    634
# Dislikes: 2368
# Total Accepted:    369.5K
# Total Submissions: 1.1M
# Testcase Example:  '"Hello World"'
#
# Given a string s consists of upper/lower-case alphabets and empty space
# characters ' ', return the length of last word (last word means the last
# appearing word if we loop from left to right) in the string.
# 
# If the last word does not exist, return 0.
# 
# Note: A word is defined as a maximal substring consisting of non-space
# characters only.
# 
# Example:
# 
# 
# Input: "Hello World"
# Output: 5
# 
# 
# 
# 
#

# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # ret = []
        # ret = s.split()
        # if len(s) == 0  or not ret: 
        #     return 0

        # return len(ret[-1])

        numlen = len(s)
        end = numlen - 1
        while end >= 0 and s[end] == ' ': 
            end -=1
        if end < 0:
            return 0
        start = end

        while start >= 0 and s[start] != ' ':
            start -= 1
        
        return (end -start)
        

if __name__ == "__main__":
    solu = Solution()
    word = "a"
    ret = solu.lengthOfLastWord(word)

    print(ret)
        
# @lc code=end

