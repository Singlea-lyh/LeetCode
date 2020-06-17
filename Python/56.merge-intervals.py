#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
# https://leetcode.com/problems/merge-intervals/description/
#
# algorithms
# Medium (38.20%)
# Likes:    4034
# Dislikes: 282
# Total Accepted:    582.3K
# Total Submissions: 1.5M
# Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
#
# Given a collection of intervals, merge all overlapping intervals.
# 
# Example 1:
# 
# 
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
# [1,6].
# 
# 
# Example 2:
# 
# 
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considered overlapping.
# 
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
# 
#

# @lc code=start
class Solution:
    def merge(self, intervals: list) -> list:
        ret = []
        numlen = len(intervals)

        if not intervals:
            return ret
        
        intervals.sort(key=lambda x: x[0])

        low , high =  intervals[0][0], intervals[0][1]

        for idx in range(1, numlen):
            if intervals[idx][0] > high or intervals[idx][1] < low:
                temp = [low, high]
                ret.append(temp)
                low, high = intervals[idx][0], intervals[idx][1]
            elif intervals[idx][0] < low and intervals[idx][1] > high:
                low,high = intervals[idx][0], intervals[idx][1]
            elif intervals[idx][0] >= low  and intervals[idx][1] >= high:
                high = intervals[idx][1]
            elif intervals[idx][0] < low and intervals[idx][1] <= high:
                low = intervals[idx][0]
       
        temp = [low, high]
        ret.append(temp)

        return ret


if __name__ == "__main__":
    solu = Solution()
    nums =[[2,3],[4,5],[6,7],[1,10]]
    ret = solu.merge(nums)

    print(ret)
# @lc code=end

