#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#
# https://leetcode.com/problems/maximal-rectangle/description/
#
# algorithms
# Hard (36.25%)
# Likes:    2861
# Dislikes: 71
# Total Accepted:    180.6K
# Total Submissions: 480.2K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
# containing only 1's and return its area.
# 
# Example:
# 
# 
# Input:
# [
# ⁠ ["1","0","1","0","0"],
# ⁠ ["1","0","1","1","1"],
# ⁠ ["1","1","1","1","1"],
# ⁠ ["1","0","0","1","0"]
# ]
# Output: 6
# 
# 
#

# @lc code=start
from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        ret = 0
        rows = len(matrix)
        if rows == 0:
            return ret
        colus = len(matrix[0])


        return ret

if __name__ == "__main__":
    solu = Solution()
    matrix = [ ["1","0","1","0","0"],
               ["1","0","1","1","1"],
               ["1","1","1","1","1"],
               ["1","0","0","1","0"]
            ]
    ret = solu.maximalRectangle(matrix)
    print(ret)
        
# @lc code=end

