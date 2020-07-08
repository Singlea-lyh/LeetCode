#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#
# https://leetcode.com/problems/search-a-2d-matrix/description/
#
# algorithms
# Medium (35.98%)
# Likes:    1756
# Dislikes: 156
# Total Accepted:    323.8K
# Total Submissions: 889.8K
# Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
#
# Write an efficient algorithm that searches for a value in an m x n matrix.
# This matrix has the following properties:
# 
# 
# Integers in each row are sorted from left to right.
# The first integer of each row is greater than the last integer of the
# previous row.
# 
# 
# Example 1:
# 
# 
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 3
# Output: true
# 
# 
# Example 2:
# 
# 
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 13
# Output: false
# 
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: list, target: int) -> bool:
        # ret = False
        # if not matrix or not matrix[0]:
        #     return ret
        
        # rows = len(matrix)
        # colus = len(matrix[0])

        # top , down, left, right = 0, rows - 1, 0, colus - 1
        # row = 0
        # mid = 0

        # while top <= down:
        #     mid = (top + down) // 2
        #     if matrix[mid][0] > target:
        #         down = mid -  1
        #     elif matrix[mid][colus - 1] < target:
        #         top = mid + 1
        #     elif matrix[mid][0] < target and matrix[mid][colus - 1] > target:
        #         row = mid
        #         break
        #     elif matrix[mid][0] ==  target or matrix[mid][colus - 1] ==  target:
        #         ret = True
        #         break
        #     else:
        #         pass
        
        # if top > down or ret:
        #     return ret
        
        # while left <= right:
        #     mid = (left + right) // 2
        #     if matrix[row][mid] > target:
        #         right = mid - 1
        #     elif matrix[row][mid] < target:
        #         left = mid + 1
        #     else:
        #         ret = True
        #         break
        # return ret

        rows = len(matrix)
        if rows == 0:
            return False
        colus = len(matrix[0])
        
        left, right = 0, rows * colus - 1
        while left <= right:
                mid = (left + right) // 2
                midnum = matrix[mid // colus][mid % colus]
                if target == midnum:
                    return True
                else:
                    if target < midnum:
                        right = mid - 1
                    else:
                        left = mid + 1
        return False

if __name__ == "__main__":
    solu = Solution()
    matrix = [[-8,-7,-5,-3,-3,-1,1],[2,2,2,3,3,5,7],[8,9,11,11,13,15,17],[18,18,18,20,20,20,21],[23,24,26,26,26,27,27],[28,29,29,30,32,32,34]]
    target = -5
    ret = solu.searchMatrix(matrix, target)
    print(ret)
        
# @lc code=end

