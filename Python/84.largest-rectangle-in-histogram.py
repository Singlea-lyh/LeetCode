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
        # ret = 0
        # heightslen = len(heights)
        # maxrect = 0
        # import sys
        # minheight = sys.maxsize

        # if heightslen == 0:
        #     return ret
        
        # start = heightslen // 2 - 1
        # end = (heightslen // 2)
        # maxrect = heights[start] if heights[start] > heights[end] else heights[end]
        # minheight = heights[start] if heights[start] < heights[end] else heights[end]
        # maxrect = (minheight * (end - start + 1)) if (minheight * (end - start + 1)) > maxrect else maxrect

        # while start > 0 or end < heightslen - 1:
        #     if start == 0:
        #         end = end + 1
        #         minheight = heights[end] if heights[end] < minheight else minheight
        #         maxrect = maxrect if maxrect > heights[end] else heights[end]
        #     elif end == heightslen - 1:
        #         start = start - 1
        #         minheight = heights[start] if heights[start] < minheight else minheight
        #         maxrect = maxrect if heights[start] < maxrect else heights[start]
        #     else:
        #         if heights[start -  1] >= heights[end + 1]:
        #             start = start - 1
        #             minheight = heights[start] if heights[start] < minheight else minheight
        #             maxrect = maxrect if heights[start] < maxrect else heights[start]
        #         else:
        #             end = end + 1
        #             minheight = heights[end] if heights[end] < minheight else minheight
        #             maxrect = maxrect if maxrect > heights[end] else heights[end]
                
        #         maxrect = maxrect if maxrect > (minheight * (end -start + 1)) else (minheight * (end -start + 1))
        
        # ret = maxrect

        # return ret

        # ret = 0 
        # heightslen = len(heights)
        # maxrect = 0
        # if heightslen == 0:
        #     return ret
        
        # maxrectarray = [[0 for _ in range(heightslen)] for _ in range(heightslen)]
        # minheightarray = [[0 for _ in range(heightslen)] for _ in range(heightslen)]
        # print(maxrectarray)

        # for i in range(heightslen):
        #     maxrectarray[i][i] = heights[i]
        #     minheightarray[i][i] = heights[i]
        #     maxrect = maxrect if maxrect > heights[i] else heights[i]
        # print(maxrectarray)
        
        # for i in range(1, heightslen):
        #     for row in range(heightslen - i):
        #         minheightarray[row][row + i] = minheightarray[row][row + i - 1] if minheightarray[row][row + i - 1] <= heights[row + i] else heights[row + i]
        #         maxtemp = maxrectarray[row][row + i - 1] if maxrectarray[row][row - 1] else maxrectarray[row + 1][row + i] 
        #         temp = minheightarray[row][row + i] * (i + 1)
        #         # print(temp)
        #         maxrectarray[row][row + i] = maxtemp if maxtemp > temp else temp
        #         maxrect = maxrect if maxrect > maxrectarray[row][row + i] else maxrectarray[row][row + i]
        
        # ret = maxrect

        # return ret


        ret = 0
        heightslen = len(heights)

        heights = [0] + heights + [0]
        size = heightslen + 2

        stack = [0]

        for i in range(1, size):
            while heights[i] < heights[stack[-1]]:
                cur_height = heights[stack.pop()]
                cur_width = i - stack[-1] - 1
                ret = max(ret, cur_height * cur_width)
            stack.append(i)

        return ret 

if __name__ == "__main__":
    solu = Solution()
    heights = [4,4,5,4,1,3]
    ret = solu.largestRectangleArea(heights)
    print(ret)
        
# @lc code=end

