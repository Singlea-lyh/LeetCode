#
# @lc app=leetcode id=87 lang=python3
#
# [87] Scramble String
#
# https://leetcode.com/problems/scramble-string/description/
#
# algorithms
# Hard (32.98%)
# Likes:    527
# Dislikes: 720
# Total Accepted:    110.8K
# Total Submissions: 329.1K
# Testcase Example:  '"great"\n"rgeat"'
#
# Given a string s1, we may represent it as a binary tree by partitioning it to
# two non-empty substrings recursively.
# 
# Below is one possible representation of s1 = "great":
# 
# 
# ⁠   great
# ⁠  /    \
# ⁠ gr    eat
# ⁠/ \    /  \
# g   r  e   at
# ⁠          / \
# ⁠         a   t
# 
# 
# To scramble the string, we may choose any non-leaf node and swap its two
# children.
# 
# For example, if we choose the node "gr" and swap its two children, it
# produces a scrambled string "rgeat".
# 
# 
# ⁠   rgeat
# ⁠  /    \
# ⁠ rg    eat
# ⁠/ \    /  \
# r   g  e   at
# ⁠          / \
# ⁠         a   t
# 
# 
# We say that "rgeat" is a scrambled string of "great".
# 
# Similarly, if we continue to swap the children of nodes "eat" and "at", it
# produces a scrambled string "rgtae".
# 
# 
# ⁠   rgtae
# ⁠  /    \
# ⁠ rg    tae
# ⁠/ \    /  \
# r   g  ta  e
# ⁠      / \
# ⁠     t   a
# 
# 
# We say that "rgtae" is a scrambled string of "great".
# 
# Given two strings s1 and s2 of the same length, determine if s2 is a
# scrambled string of s1.
# 
# Example 1:
# 
# 
# Input: s1 = "great", s2 = "rgeat"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s1 = "abcde", s2 = "caebd"
# Output: false
# 
#

# @lc code=start
from typing import List

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        ret = False
        s1len = len(s1)
        s2len = len(s2)

        if s1len != s2len:
            return ret

        slen = s1len

        dp = [[[False for _ in range(slen + 1)] for _ in range(slen)] for _ in range(slen)]
        # print(dp)

        for i in range(slen):
            for j in range(slen):
                dp[i][j][1] = (s1[i] == s2[j])
        
        # print(dp)

        for complen in range(2, slen + 1):
            for i in range(slen - complen + 1):
                for j in range(slen - complen + 1):
                    for k in range(1, complen):
                        if (dp[i][j][k] and dp[i + k][j + k][complen - k]):
                            dp[i][j][complen] = True
                            break
                        if (dp[i][j + complen -k][k] and dp[i + k][j][complen -  k]):
                            dp[i][j][complen] = True
                            break

        ret = dp[0][0][slen]

        return ret

if __name__ == "__main__":
    solu = Solution()
    s1 = "abcde"
    s2 = "caebd"

    ret = solu.isScramble(s1, s2)

    print(ret)
        
# @lc code=end

