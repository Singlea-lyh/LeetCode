#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#
# https://leetcode.com/problems/n-queens/description/
#
# algorithms
# Hard (44.32%)
# Likes:    1740
# Dislikes: 69
# Total Accepted:    195.8K
# Total Submissions: 430.8K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
# 
# 
# 
# Given an integer n, return all distinct solutions to the n-queens puzzle.
# 
# Each solution contains a distinct board configuration of the n-queens'
# placement, where 'Q' and '.' both indicate a queen and an empty space
# respectively.
# 
# Example:
# 
# 
# Input: 4
# Output: [
# ⁠[".Q..",  // Solution 1
# ⁠ "...Q",
# ⁠ "Q...",
# ⁠ "..Q."],
# 
# ⁠["..Q.",  // Solution 2
# ⁠ "Q...",
# ⁠ "...Q",
# ⁠ ".Q.."]
# ]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as
# shown above.
# 
# 
#

# @lc code=start

import os
class Solution:
    def solveNQueens(self, n: int) -> list:
        def could_place(row, col):
            return not (cols[col] + add_diag[row + col] + sub_diag[row - col])
        
        def place_queen(row, col):
            queen.add((row, col))
            cols[col] = 1
            add_diag[row + col] = 1
            sub_diag[row - col] = 1
        
        def remove_queen(row, col):
            queen.remove((row, col))
            cols[col] = 0
            add_diag[row + col] = 0
            sub_diag[row - col] = 0
        
        def add_solution():
            solve = []
            for _, col in sorted(queen):
                solve.append("." * col + "Q" + "." * (n - col - 1))
            output.append(solve)

        def backtrack(row = 0):
            for col in range(n):
                if could_place(row, col):
                    place_queen(row, col)
                    if row + 1 == n:
                        add_solution()
                    else:
                        backtrack(row + 1)
                    remove_queen(row, col)
        
        cols = [0] * n
        add_diag = [0] * (2 * n - 1)
        sub_diag = [0] * (2 * n - 1)
        queen = set()
        output = []
        backtrack()       
        return output

# class Solution:
#     def test(self, n):
#         input = [0] * n
#         return input

if __name__ == "__main__":
    nqueen = Solution()
    ret = nqueen.solveNQueens(4)
    for i in ret:
        print("[", end = "")
        for j in i:
            print(j)
        print("]")

        
    # print(nqueen.solveNQueens(4)) 






# @lc code=end

