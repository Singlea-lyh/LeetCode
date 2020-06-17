#
# @lc app=leetcode id=54 lang=python3
#
# [54] Spiral Matrix
#
# https://leetcode.com/problems/spiral-matrix/description/
#
# algorithms
# Medium (32.98%)
# Likes:    2227
# Dislikes: 557
# Total Accepted:    358.9K
# Total Submissions: 1.1M
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# Given a matrix of m x n elements (m rows, n columns), return all elements of
# the matrix in spiral order.
# 
# Example 1:
# 
# 
# Input:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 4, 5, 6 ],
# ⁠[ 7, 8, 9 ]
# ]
# Output: [1,2,3,6,9,8,7,4,5]
# 
# 
# Example 2:
# 
# Input:
# [
# ⁠ [1, 2, 3, 4],
# ⁠ [5, 6, 7, 8],
# ⁠ [9,10,11,12]
# ]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]
# 
#

# @lc code=start
class Solution:
    def spiralOrder(self, matrix:list) -> list:
        def recurrence(left, right, top, bottle):
            # print(left, right, top, bottle)
            if left > right or top > bottle:

                return

            for colu in range(left, right + 1):
                # print(colu)
                ret.append(matrix[top][colu])
                # print(ret)
            for row in range(top + 1, bottle + 1):
                ret.append(matrix[row][right])
            if left < right and top < bottle:
                for colu in range(right - 1, left, -1):
                    ret.append(matrix[bottle][colu])
                for row in range(bottle, top, -1):
                    ret.append(matrix[row][left])

            recurrence(left + 1, right - 1, top + 1, bottle - 1)

            return 
        
        ret = []
        if not matrix or not matrix[0]:
            return ret
        rows = len(matrix)
        columns = len(matrix[0])

        recurrence(0, columns - 1, 0, rows - 1)

        # total = rows * columns
        # print(total)

        return ret



        
        # ret = []
       
        # if not matrix or not matrix[0]:
        #     return ret
        
        # rows = len(matrix)
        # columns = len(matrix[0])

        # total = rows * columns
        # print(total)

        # top = 0
        # left = 0
        # bottle = rows - 1
        # right = columns - 1

        # while left <= right and top <= bottle:
        #     for  colu in range(left, right + 1):
        #         ret.append(matrix[top][colu])
        #     for row in range(top + 1, bottle + 1):
        #         ret.append(matrix[row][right])
        #     if left < right and top < bottle:
        #         for colu in range(right - 1, left, -1):
        #             ret.append(matrix[bottle][colu])
        #         for row in range(bottle, top, -1):
        #             ret.append(matrix[row][left])
        #     left,right,top,bottle = left + 1, right - 1, top + 1, bottle - 1
        # return ret

if __name__ == "__main__":
    solu = Solution()
    matrix =  [[1,2,3],[4,5,6],[7,8,9]]
    # print(matrix)
    ret = solu.spiralOrder(matrix)

    print(ret)
# @lc code=end

