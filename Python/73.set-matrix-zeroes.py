#
# @lc app=leetcode id=73 lang=python3
#
# [73] Set Matrix Zeroes
#
# https://leetcode.com/problems/set-matrix-zeroes/description/
#
# algorithms
# Medium (42.22%)
# Likes:    2084
# Dislikes: 299
# Total Accepted:    315.3K
# Total Submissions: 734.9K
# Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
#
# Given a m x n matrix, if an element is 0, set its entire row and column to 0.
# Do it in-place.
# 
# Example 1:
# 
# 
# Input: 
# [
# [1,1,1],
# [1,0,1],
# [1,1,1]
# ]
# Output: 
# [
# [1,0,1],
# [0,0,0],
# [1,0,1]
# ]
# 
# 
# Example 2:
# 
# 
# Input: 
# [
# [0,1,2,0],
# [3,4,5,2],
# [1,3,1,5]
# ]
# Output: 
# [
# [0,0,0,0],
# [0,4,5,0],
# [0,3,1,0]
# ]
# 
# 
# Follow up:
# 
# 
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best
# solution.
# Could you devise a constant space solution?
# 
# 
#

# @lc code=start
class Solution:
    def setZeroes(self, matrix: list) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # ret = []
        if not matrix:
            return matrix
        rowslen= len(matrix)
        coluslen = len(matrix[0])
        row_flag  = False
        colu_flag = False

        for row in range(rowslen):
            if matrix[row][0] == 0:
                colu_flag = True
                break
        for colu in range(coluslen):
            if matrix[0][colu] == 0:
                row_flag = True
                break
        for row in range(1, rowslen):
            for colu in range(1, coluslen):
                if matrix[row][colu] == 0:
                    matrix[0][colu] = matrix[row][0] = 0

        for row in range(1, rowslen):
            for colu in range(1, coluslen):
                if matrix[0][colu] == 0 or matrix[row][0] == 0:
                    matrix[row][colu] = 0

        if row_flag:
            for colu in range(coluslen):
                matrix[0][colu] = 0
        if colu_flag:
            for row in range(rowslen):
                matrix[row][0] = 0

        return matrix


if __name__ == "__main__":
    solu = Solution()
    matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    ret = solu.setZeroes(matrix)

    print(ret)
        
# @lc code=end

