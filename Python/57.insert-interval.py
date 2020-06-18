#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#
# https://leetcode.com/problems/insert-interval/description/
#
# algorithms
# Hard (32.74%)
# Likes:    1546
# Dislikes: 179
# Total Accepted:    245.4K
# Total Submissions: 739K
# Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
#
# Given a set of non-overlapping intervals, insert a new interval into the
# intervals (merge if necessary).
# 
# You may assume that the intervals were initially sorted according to their
# start times.
# 
# Example 1:
# 
# 
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
# 
# 
# Example 2:
# 
# 
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with
# [3,5],[6,7],[8,10].
# 
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
# 
#

# @lc code=start
class Solution:
    def insert(self, intervals: list, newInterval: list) -> list:
        # ret = []
        # temp = []
        # ismatch = True
        # # intervalslen = len(intervals)
        # intervals.sort(key = lambda x : x [0])
        # print(intervals)

        # left , right = newInterval[0], newInterval[1]
        
        # if not intervals:
        #     ret.append(newInterval)
        #     return ret

        # for interval in intervals:
        #     if interval[1] < newInterval[0]:
        #         ret.append(interval)
            
        #     if ismatch:
        #         if interval[1] >= left : left = min(left, interval[0])
        #         if interval[0] <= right : right = max(right, interval[1])
        #         if interval[0] > right or interval == intervals[-1]:
        #             ret.append([left, right])
        #             ismatch = False
        #     if interval[0] > newInterval[1]:
        #         ret.append(interval)

        # return ret

        ret = []
        new_left, new_right = newInterval

        if not intervals:
            ret.append(newInterval)
            return ret
        numlen = len(intervals)

        idx = 0
        
        while idx < numlen and intervals[idx][0] < new_left:
            ret.append(intervals[idx])
            idx += 1
        
        if not ret or ret[-1][1] < new_left:
            ret.append(newInterval)
        else:
            ret[-1][1] = max(ret[-1][1], new_right)
        
        while idx < numlen:
            left, right = intervals[idx]
            idx += 1
            if ret[-1][1] < left:
                ret.append([left, right])
            else:
                ret[-1][1] = max(ret[-1][1], right)

        return ret



if __name__ == "__main__":
    solu = Solution()
    intervals =[[1,2],[3,5],[6,7],[8,10],[12,16]]


    newInterval = [4,8]
    ret = solu.insert(intervals, newInterval)

    print(ret)

        
# @lc code=end

