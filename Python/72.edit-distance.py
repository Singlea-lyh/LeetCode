#
# @lc app=leetcode id=72 lang=python3
#
# [72] Edit Distance
#
# https://leetcode.com/problems/edit-distance/description/
#
# algorithms
# Hard (41.72%)
# Likes:    3894
# Dislikes: 56
# Total Accepted:    277.8K
# Total Submissions: 627.7K
# Testcase Example:  '"horse"\n"ros"'
#
# Given two words word1 and word2, find the minimum number of operations
# required to convert word1 to word2.
# 
# You have the following 3 operations permitted on a word:
# 
# 
# Insert a character
# Delete a character
# Replace a character
# 
# 
# Example 1:
# 
# 
# Input: word1 = "horse", word2 = "ros"
# Output: 3
# Explanation: 
# horse -> rorse (replace 'h' with 'r')
# rorse -> rose (remove 'r')
# rose -> ros (remove 'e')
# 
# 
# Example 2:
# 
# 
# Input: word1 = "intention", word2 = "execution"
# Output: 5
# Explanation: 
# intention -> inention (remove 't')
# inention -> enention (replace 'i' with 'e')
# enention -> exention (replace 'n' with 'x')
# exention -> exection (replace 'n' with 'c')
# exection -> execution (insert 'u')
# 
# 
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # ret = 0
        # word1len = len(word1)
        # word2len = len(word2)

        # dp = [[0] * (word2len + 1) for _ in range(word1len + 1)]
       
        # dp[0][0] = 0

        # for colu in range(1, word2len + 1): 
        #     dp[0][colu] = colu
        # for row in range(1, word1len + 1):
        #     dp[row][0] = row
        # # print(dp)

        # for row in range(1, word1len + 1):
        #     for colu in range(1, word2len + 1):
        #         left = dp[row][colu - 1] + 1
        #         down = dp[row - 1][colu] + 1
        #         left_down = dp[row - 1][colu - 1]
        #         if word1[row - 1] == word2[colu - 1]:
        #            left_down = dp[row - 1][colu  -1]
        #         else:
        #             left_down = dp[row - 1][colu - 1] + 1
        #         dp[row][colu] = min(min(left, down), left_down)
            
        # # print(dp)
        # ret = dp[-1][-1]

              
        # return ret

        import functools
        @functools.lru_cache(None)
        def helper(i, j):
            if i == len(word1) or j == len(word2):
                return len(word1) - i + len(word2) - j
            if word1[i] == word2[j]:
                return helper(i + 1, j + 1)
            else:
                inserted = helper(i, j + 1)
                deleted = helper(i + 1, j)
                replaced = helper(i + 1, j + 1)
                return min(inserted, deleted, replaced) + 1
        return helper(0, 0)


if __name__ == "__main__":
    solu = Solution()
    word1 = "horse"
    word2 = "ros"
    ret = solu.minDistance(word1, word2)

    print(ret)
        
# @lc code=end

