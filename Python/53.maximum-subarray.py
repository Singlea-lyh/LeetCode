#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (45.95%)
# Likes:    7657
# Dislikes: 356
# Total Accepted:    1M
# Total Submissions: 2.2M
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# Given an integer array nums, find the contiguous subarray (containing at
# least one number) which has the largest sum and return its sum.
# 
# Example:
# 
# 
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
# 
# 
# Follow up:
# 
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
# 
#

# @lc code=start
import os
import sys
from collections import namedtuple

# rettree = namedtuple("rettree", ['lsum', 'rsum', 'msum', 'tsum'])

class Solution: 
    def maxSubArray(self, nums:list)->int:
        def mergemax(leftret, rightret):
            lmax = leftret.lsum if leftret.lsum > (leftret.tsum + rightret.lsum) else leftret.tsum + rightret.lsum
            rmax = rightret.rsum if rightret.rsum > (leftret.rsum + rightret.tsum) else leftret.rsum + rightret.tsum
            mmax = max(max(leftret.msum, rightret.msum), leftret.rsum + rightret.lsum)
            tmax = leftret.tsum + rightret.tsum
            ret = rettree(lmax, rmax, mmax, tmax)
            return ret

        def gettree(nums, start, end):
            if start == end:
                ret = rettree(nums[start], nums[start], nums[start], nums[start])
                # print(ret)
                return ret

            mid = (start + end) // 2

            leftret = gettree(nums, start, mid)
            rightret = gettree(nums, mid + 1, end)
            ret = mergemax(leftret, rightret)
            
            return ret

        rettree = namedtuple("rettree", ['lsum', 'rsum', 'msum', 'tsum'])
        ret = gettree(nums, 0, len(nums) - 1)
        print(ret)
        return ret.msum
            
    # def maxSubArray(self, nums:list)->int:
    #     maxsub = -sys.maxsize - 1
    #     tempsub = 0
    #     ret = []
    #     startidx = 0
    #     endidx = 0
    #     idx = 0

    #     for idx in range(len(nums)): 
    #         tempsub = tempsub + nums[idx]
    #         if tempsub < nums[idx]:
    #             tempsub = nums[idx]
    #             startidx = idx
    #         if tempsub > maxsub:
    #             maxsub = tempsub
    #             endidx = idx

    #     ret = nums[startidx:endidx + 1]
    #     print(ret)

             
        # return maxsub


    # def maxSubArray(self, nums:list)->int:
    #     maxsub = nums[0]
    #     premax = 0
    #     idx = 0

    #     for idx in range(len(nums)): 
    #         premax = max(premax + nums[idx], nums[idx])
    #         maxsub = max(premax, maxsub)  
 


if __name__ == "__main__":
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    solution = Solution()
    ret = solution.maxSubArray(nums)

    print(ret)

        
# @lc code=end

