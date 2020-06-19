#
# @lc app=leetcode id=59 lang=python3
#
# [59] Spiral Matrix II
#
# https://leetcode.com/problems/spiral-matrix-ii/description/
#
# algorithms
# Medium (51.78%)
# Likes:    928
# Dislikes: 107
# Total Accepted:    189.2K
# Total Submissions: 356.9K
# Testcase Example:  '3'
#
# Given a positive integer n, generate a square matrix filled with elements
# from 1 to n^2 in spiral order.
# 
# Example:
# 
# 
# Input: 3
# Output:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 8, 9, 4 ],
# ⁠[ 7, 6, 5 ]
# ]
# 
# 
#

# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> list:
        ret = [ [0] * n for _ in range(n)]
        # ret = [ [0] * n] * n
        # ret = [[0  for _ in range(n)] for _ in range(n)]
        # print(ret)
        # elemnum = n * n

        if n == 0:
            return [[]]

        top = 0
        bottle = n - 1
        left = 0
        right = n - 1

        idx = 1

        while left <= right and top <= bottle:
            for colu in range(left, right + 1):
                ret[top][colu] = idx
                idx += 1
            for row in range(top + 1, bottle + 1):
                ret[row][right] = idx
                idx += 1
            for colu in range(right - 1, left, -1):
                ret[bottle][colu] = idx
                idx += 1
            for row in range(bottle, top, -1):
                ret[row][left] = idx
                idx += 1
            left, right, top, bottle = left + 1, right - 1, top + 1, bottle - 1


        return ret


if __name__ == "__main__":
    solu = Solution()
    nlen = 10
    ret = solu.generateMatrix(nlen)

    print(ret)
        
# @lc code=end

