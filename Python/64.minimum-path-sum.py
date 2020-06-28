#
# @lc app=leetcode id=64 lang=python3
#
# [64] Minimum Path Sum
#
# https://leetcode.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (51.36%)
# Likes:    2965
# Dislikes: 61
# Total Accepted:    415K
# Total Submissions: 770.2K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# Given a m x n grid filled with non-negative numbers, find a path from top
# left to bottom right which minimizes the sum of all numbers along its path.
# 
# Note: You can only move either down or right at any point in time.
# 
# Example:
# 
# 
# Input:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
# 
# 
#

# @lc code=start
class Solution:
    def minPathSum(self, grid: list) -> int:
        ret = 0


        print(ret)

if __name__ == "__main__":
    solu = Solution()
    grid = [[1,3,1], [1,5,1],⁠ [4,2,1]]

    ret = solu.minPathSum(grid)

    print(ret)
        
# @lc code=end

