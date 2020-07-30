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
        # ret = 0
        # maxmal = 0
        # rows = len(matrix)
        # if rows == 0:
        #     return ret
        # colus = len(matrix[0])

        # maxmatrix = [[0 for _ in range(colus)] for _ in range(rows)]
        # print(maxmatrix)

        # for row in range(rows):
        #     for col in range(colus):
        #         if matrix[row][col] == "1":
        #             if col == 0:
        #                 maxmatrix[row][col] = 1
        #             else:
        #                 maxmatrix[row][col] = maxmatrix[row][col - 1] + 1
        #         else:
        #             maxmatrix[row][col] = 0
        
        #         minwidth = maxmatrix[row][col]

        #         for cur_row in range(row, -1, -1):
        #             height = row - cur_row + 1
        #             minwidth = min(minwidth, maxmatrix[cur_row][col])
        #             maxmal = max(maxmal, height * minwidth)

        # ret = maxmal
                
        # return ret

        # def largestrectangle(heights):
        #     maxrect = 0
        #     heightslen = len(heights)

        #     stack = [0]
        #     heights = [0] + heights + [0]
        #     size = heightslen + 2

        #     for col in range(1, size):
        #         while heights[col] < heights[stack[-1]]:
        #             height = heights[stack.pop()]
        #             length = col - stack[-1] - 1
        #             maxrect = max(maxrect, height * length)
        #         stack.append(col)
        #     return maxrect

        # ret = 0
        # maxret = 0
        # rows = len(matrix)
        # if rows == 0:
        #     return ret
        
        # colus = len(matrix[0])
        # rowheights = [0 for _ in range(colus)]

        # for row in range(rows):
        #     for colu in range(colus):
        #         if matrix[row][colu] == "1":
        #             rowheights[colu] += 1
        #         else:
        #             rowheights[colu] = 0
        #     maxret = max(maxret, largestrectangle(rowheights))
        # ret = maxret
        # return ret
        ret = 0
        maxret = 0
        rows = len(matrix)
        if rows == 0:
            return ret
        
        colus = len(matrix[0])
        rowheights = [0 for _ in range(colus)]
        leftless = [-1 for _ in range(colus)]
        rightless = [colus for _ in range(colus)]

        for row in range(rows):
            for colu in range(colus):
                if matrix[row][colu] == "1":
                    rowheights[colu] += 1
                else:
                    rowheights[colu] = 0

            bound = -1 
            for colu in range(colus):
                if matrix[row][colu] == "1":
                    leftless[colu] = max(leftless[colu], bound)
                else:
                    leftless[colu] = -1
                    bound = colu

            bound = colus
            for colu in range(colus - 1, -1, -1): 
                if matrix[row][colu] == "1":
                    rightless[colu] = min(rightless[colu], bound)
                else:
                    rightless[colu] = colus
                    bound = colu
            print(matrix[row])
            print(leftless)
            print(rightless)
            
            for colu in range(colus -  1, -1 , -1):
                maxret = max(maxret, (rightless[colu] - leftless[colu] -  1) * rowheights[colu]) 
        
        ret = maxret

        return ret
        
if __name__ == "__main__":
    solu = Solution()
    matrix = [ ["1","0","1","0","0"],
               ["1","0","1","1","1"],
               ["1","1","1","1","1"],
               ["1","0","0","1","0"]
            ]
    # matrix = [["1","0"]]
    ret = solu.maximalRectangle(matrix)
    print(ret)
        
# @lc code=end

