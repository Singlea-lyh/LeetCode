#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
# https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#
# algorithms
# Hard (33.73%)
# Likes:    3771
# Dislikes: 86
# Total Accepted:    267K
# Total Submissions: 763.2K
# Testcase Example:  '[2,1,5,6,2,3]'
#
# Given n non-negative integers representing the histogram's bar height where
# the width of each bar is 1, find the area of largest rectangle in the
# histogram.
# 
# 
# 
# 
# Above is a histogram where width of each bar is 1, given height =
# [2,1,5,6,2,3].
# 
# 
# 
# 
# The largest rectangle is shown in the shaded area, which has area = 10
# unit.
# 
# 
# 
# Example:
# 
# 
# Input: [2,1,5,6,2,3]
# Output: 10
# 
# 
#

# @lc code=start
from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ret = 0

        return ret

if __name__ == "__main__":
    solu = Solution()
    heights = [2,1,5,6,2,3]
    ret = solu.largestRectangleArea(heights)
    print(ret)
        
# @lc code=end

