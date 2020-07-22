#
# @lc app=leetcode id=81 lang=python3
#
# [81] Search in Rotated Sorted Array II
#
# https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
#
# algorithms
# Medium (32.95%)
# Likes:    1303
# Dislikes: 477
# Total Accepted:    239.8K
# Total Submissions: 726.6K
# Testcase Example:  '[2,5,6,0,0,1,2]\n0'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
# 
# (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
# 
# You are given a target value to search. If found in the array return true,
# otherwise return false.
# 
# Example 1:
# 
# 
# Input: nums = [2,5,6,0,0,1,2], target = 0
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: nums = [2,5,6,0,0,1,2], target = 3
# Output: false
# 
# Follow up:
# 
# 
# This is a follow up problem to Search in Rotated Sorted Array, where nums may
# contain duplicates.
# Would this affect the run-time complexity? How and why?
# 
# 
#

# @lc code=start
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        def binarysearch(start, end):
            mid = 0
            if start == end:
                if nums[start] == target:
                    return True
                else:
                    return False
            elif start < end:
                mid = (start + end) // 2
                if nums[mid] == target:
                    return True
                elif nums[mid] < target:
                    if nums[mid] <= nums[start]:
                        return binarysearch(start, mid -1) or binarysearch(mid + 1, end)
                    else:
                        return binarysearch(mid + 1, end)
                else:
                    if nums[mid] < nums[start]:
                        return binarysearch(start, mid - 1)
                    else:
                        return binarysearch(start, mid - 1) or binarysearch(mid + 1, end)
            else:
                return False

        ret = False
        numslen = len(nums)
        if numslen == 0:
            return ret
        start = 0
        end = numslen - 1
        mid = 0

        ret = binarysearch(start, end)

        return ret

if __name__ == "__main__":
    solu = Solution()
    nums = [3,1]
    target = 1
    ret = solu.search(nums, target)
    print(ret)
        
# @lc code=end

