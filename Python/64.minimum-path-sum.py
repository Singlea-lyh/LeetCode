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
        # ret = 0

        # if not grid:
        #     return ret

        # rowlen = len(grid)
        # colulen = len(grid[0])

        # matrix = [[0] * colulen for _ in range(rowlen)]
        # matrix[0][0] = grid[0][0]

        # for row in range(1, rowlen):
        #     matrix[row][0] = matrix[row - 1][0] + grid[row][0]
        #     # tempmin = min(tempmin, matrix[row][0])
        # for colu in range(1, colulen):
        #     matrix[0][colu] =  matrix[0][colu - 1] + grid[0][colu]
        #     # tempmin = tempmin if tempmin < grid[0][colu] else grid[0][colu]

        # print(matrix)
        
        # for row in range(1, rowlen):
        #     for colu in range(1, colulen):
        #         matrix[row][colu] = min(matrix[row - 1][colu] , matrix[row][colu - 1] ) + grid[row][colu]
        
        # ret = matrix[-1][-1]

        # return ret


        ret = 0

        if not grid:
            return ret

        rowlen = len(grid)
        colulen = len(grid[0])

        matrix = [0 for _ in range(colulen)]
        matrix[0] = grid[0][0]

       
        for colu in range(1, colulen):
            matrix[colu] =  matrix[colu - 1] + grid[0][colu]

        # print(matrix)
        
        for row in range(1, rowlen):
            for colu in range(colulen):
                if colu == 0:
                    matrix[colu] = matrix[colu] + grid[row][colu]
                else:
                    matrix[colu] = min(matrix[colu] , matrix[colu - 1]) + grid[row][colu]
            # print(matrix)

        
        ret = matrix[-1]

        return ret

if __name__ == "__main__":
    solu = Solution()
    grid = [[1,3,1],[1,5,1],[4,2,1]]

    ret = solu.minPathSum(grid)

    print(ret)
        
# @lc code=end

