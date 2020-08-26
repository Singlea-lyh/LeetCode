#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#
# https://leetcode.com/problems/decode-ways/description/
#
# algorithms
# Medium (23.82%)
# Likes:    2849
# Dislikes: 2951
# Total Accepted:    416.4K
# Total Submissions: 1.7M
# Testcase Example:  '"12"'
#
# A message containing letters from A-Z is being encoded to numbers using the
# following mapping:
# 
# 
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# 
# 
# Given a non-empty string containing only digits, determine the total number
# of ways to decode it.
# 
# Example 1:
# 
# 
# Input: "12"
# Output: 2
# Explanation: It could be decoded as "AB" (1 2) or "L" (12).
# 
# 
# Example 2:
# 
# 
# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
# 6).
# 
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        ret = 0
        slen = len(s)
        if slen == 0:
            return ret

        dp = [0 for _ in range(slen)]

        if s[0] == '0':
            return ret

        dp[0] = 1
        for idx in range(1, slen):
            if s[idx] != '0':
                dp[idx] = dp[idx - 1]
            tempnum = 10 * (ord(s[idx - 1]) - ord('0')) +  (ord(s[idx]) - ord('0'))

            if 10 <= tempnum <= 26:
                if idx == 1:
                    dp[idx] += 1
                else:
                    dp[idx] += dp[idx - 2]
        
        ret = dp[slen - 1]

        return ret 

if __name__ == "__main__":
    solu = Solution()
    s = "12"
    ret = solu.numDecodings(s)
    print(ret)
        
# @lc code=end

