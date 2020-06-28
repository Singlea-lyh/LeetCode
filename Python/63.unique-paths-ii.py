#
# @lc app=leetcode id=63 lang=python3
#
# [63] Unique Paths II
#
# https://leetcode.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (33.96%)
# Likes:    1646
# Dislikes: 234
# Total Accepted:    288.9K
# Total Submissions: 843.2K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in
# the diagram below).
# 
# The robot can only move either down or right at any point in time. The robot
# is trying to reach the bottom-right corner of the grid (marked 'Finish' in
# the diagram below).
# 
# Now consider if some obstacles are added to the grids. How many unique paths
# would there be?
# 
# 
# 
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
# 
# Note: m and n will be at most 100.
# 
# Example 1:
# 
# 
# Input:
# [
# [0,0,0],
# [0,1,0],
# [0,0,0]
# ]
# Output: 2
# Explanation:
# There is one obstacle in the middle of the 3x3 grid above.
# There are two ways to reach the bottom-right corner:
# 1. Right -> Right -> Down -> Down
# 2. Down -> Down -> Right -> Right
# 
# 
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: list) -> int:
        # ret = 0 
        # if not obstacleGrid:
        #     return ret
        # rowlen = len(obstacleGrid)
        # colulen = len(obstacleGrid[0])

        # obstaclelist = [[0] * colulen for _ in range(rowlen)]
        # print(obstaclelist)

        # for row in range(rowlen):
        #     if obstacleGrid[row][0] == 1:
        #         break
        #     obstaclelist[row][0] = 1
        # for colu in range(colulen):
        #     if obstacleGrid[0][colu]:
        #         break
        #     obstaclelist[0][colu] = 1
        # print(obstaclelist)

        # for row in range(1, rowlen):
        #     for colu in range(1, colulen):
        #         if obstacleGrid[row][colu] == 1:
        #             obstaclelist[row][colu] = 0
        #         else:
        #             obstaclelist[row][colu] = obstaclelist[row - 1][colu] + obstaclelist[row][colu - 1]
        
        # ret = obstaclelist[-1][-1]
        # return ret

        ret = 0 
        if not obstacleGrid:
            return ret
        rowlen = len(obstacleGrid)
        colulen = len(obstacleGrid[0])

        prelist = [0 for _ in range(colulen)]
        for colu in range(colulen):
            if obstacleGrid[0][colu] == 1:
                break
            prelist[colu] = 1
        for row in range(1, rowlen):
            for colu in range(colulen):
                if obstacleGrid[row][colu] == 1:
                    prelist[colu] = 0
                else:
                    if colu > 0: 
                        prelist[colu] += prelist[colu - 1]
                    else:
                        prelist[colu] = prelist[colu]
        ret = prelist[-1]

        return ret
                 

if __name__ == "__main__":
    solu = Solution()
    obstacles =[[1],[0]]

    ret = solu.uniquePathsWithObstacles(obstacles)

    print(ret)
    
        
# @lc code=end

