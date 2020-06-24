#
# @lc app=leetcode id=62 lang=python3
#
# [62] Unique Paths
#
# https://leetcode.com/problems/unique-paths/description/
#
# algorithms
# Medium (51.70%)
# Likes:    3039
# Dislikes: 202
# Total Accepted:    453.4K
# Total Submissions: 859K
# Testcase Example:  '3\n2'
#
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in
# the diagram below).
# 
# The robot can only move either down or right at any point in time. The robot
# is trying to reach the bottom-right corner of the grid (marked 'Finish' in
# the diagram below).
# 
# How many possible unique paths are there?
# 
# 
# Above is a 7 x 3 grid. How many possible unique paths are there?
# 
# 
# Example 1:
# 
# 
# Input: m = 3, n = 2
# Output: 3
# Explanation:
# From the top-left corner, there are a total of 3 ways to reach the
# bottom-right corner:
# 1. Right -> Right -> Down
# 2. Right -> Down -> Right
# 3. Down -> Right -> Right
# 
# 
# Example 2:
# 
# 
# Input: m = 7, n = 3
# Output: 28
# 
# 
# 
# Constraints:
# 
# 
# 1 <= m, n <= 100
# It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
# 
# 
#

# @lc code=start
class Solution:
    # def uniquePaths(self, m: int, n: int) -> int:
        # def recurrence(row, rows, col, cols, temp, ret):
        #     if row == rows and col == cols:
        #         result.append(temp)
        #         ret += 1
        #         return ret
            # elif row == rows:
            #     tempcol = col + 1
            #     while col != cols:
            #         temp.append("Right")
            #         col += 1
            #     result.append(temp)
            #     while col != tempcol:
            #         del temp[-1]
            #         col -= 1
            #     ret += 1
            #     return ret
            # elif col == cols:
            #     temprow = row + 1
            #     while row != rows:
            #         temp.append("Down")
            #         row += 1
            #     while row != temprow:
            #         del temp[-1]
            #         row -= 1
            #     result.append(temp)
            #     ret += 1
            #     return ret
            # else:
            #     if row == rows:
            #         temp.append("Right")
            #         ret = recurrence(row, rows, col + 1, cols, temp, ret)
            #     elif col == cols:
            #         temp.append("Down")
            #         ret = recurrence(row + 1, rows, col, cols, temp, ret)
            #     else:
            #         for i in range(2):
            #             if i == 0:
            #                 temp.append("Right")
            #                 ret = recurrence(row, rows, col + 1, cols, temp, ret)
            #             else:
            #                 temp.append("Down")
            #                 ret = recurrence(row + 1, rows, col, cols, temp, ret)
            #     del temp[-1]



            # if col < cols : 
            #     ret = recurrence(row, rows, col + 1, cols, temp, ret)
            # if row < rows:
            #     ret = recurrence(row + 1, rows, col, col + 1, temp, ret)
            
            # return ret

        # ret = 0
        # result = []
        # temp = []
        # ret  = recurrence(0, n - 1, 0, m - 1, temp, ret)
        # # print(result)

        # return ret

        def uniquePaths(self, m: int, n: int) -> int:
            # ret = 0
            # temp = [[1] * m] + [[1] + [0] * (m - 1) for _ in range(n - 1)]
            # print(temp)
            # print(temp[1][0])

            # for col in range(1, n):
            #     for row in range(1, m):
            #         temp[col][row] = temp[col - 1][row] + temp[col][row - 1]
            
            # ret = temp[-1][-1]

            # return ret 

            # ret =  0 
            # precols = [1] * m
            # cols = [1] * m

            # for _ in range(1, n):
            #     for col in range(1, m):
            #         cols[col] = cols[col - 1] + precols[col]
            #     precols = cols[:] 

            # ret = precols[-1]

            # return ret 

            ret =  0 
            cols = [1] * m

            for _ in range(1, n):
                for col in range(1, m):
                    cols[col] += cols[col - 1]
            ret = cols[-1]

            return ret 




if __name__ == "__main__":
    solu = Solution()
    row = 3
    col = 2

    ret = solu.uniquePaths(row, col)

    print(ret)
        
# @lc code=end

