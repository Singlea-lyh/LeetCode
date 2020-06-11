#
# @lc app=leetcode id=52 lang=python3
#
# [52] N-Queens II
#
# https://leetcode.com/problems/n-queens-ii/description/
#
# algorithms
# Hard (56.00%)
# Likes:    473
# Dislikes: 145
# Total Accepted:    130.1K
# Total Submissions: 228.5K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
# 
# 
# 
# Given an integer n, return the number of distinct solutions to the n-queens
# puzzle.
# 
# Example:
# 
# 
# Input: 4
# Output: 2
# Explanation: There are two distinct solutions to the 4-queens puzzle as shown
# below.
# [
# [".Q..",  // Solution 1
# "...Q",
# "Q...",
# "..Q."],
# 
# ["..Q.",  // Solution 2
# "Q...",
# "...Q",
# ".Q.."]
# ]
# 
# 
#

# @lc code=start

import os
class Solution:
    def totalNQueens(self, n: int) -> int:  
        def could_place(row, col):
            return not (cols[col] or add_diga[row + col] or sub_diga[row - col])
        
        def queen_palce(row, col):
            cols[col] = 1
            add_diga[row + col] = 1
            sub_diga[row - col] = 1
        
        def queen_remove(row, col):
            cols[col] = 0
            add_diga[row + col] = 0
            sub_diga[row - col] = 0
        
        def backtrack(row = 0, ret = 0):
            if row == n:
                ret +=  1
                return ret
            
            for col in range(n):
                if could_place(row, col):
                    queen_palce(row, col)
                    ret = backtrack(row + 1, ret)
                    queen_remove(row, col)
            return ret
        
        cols = [0] * n
        add_diga = [0] * (2 * n -1)
        sub_diga = [0] * (2 * n - 1)
        return backtrack()


if __name__ == "__main__":
    solu = Solution()
    ret = solu.totalNQueens(4)
    print(ret)

        
# @lc code=end

