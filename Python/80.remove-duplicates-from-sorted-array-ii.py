#
# @lc app=leetcode id=80 lang=python3
#
# [80] Remove Duplicates from Sorted Array II
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
#
# algorithms
# Medium (42.80%)
# Likes:    1162
# Dislikes: 701
# Total Accepted:    264.8K
# Total Submissions: 604.6K
# Testcase Example:  '[1,1,1,2,2,3]'
#
# Given a sorted array nums, remove the duplicates in-place such that
# duplicates appeared at most twice and return the new length.
# 
# Do not allocate extra space for another array, you must do this by modifying
# the input array in-place with O(1) extra memory.
# 
# Example 1:
# 
# 
# Given nums = [1,1,1,2,2,3],
# 
# Your function should return length = 5, with the first five elements of nums
# being 1, 1, 2, 2 and 3 respectively.
# 
# It doesn't matter what you leave beyond the returned length.
# 
# Example 2:
# 
# 
# Given nums = [0,0,1,1,1,1,2,3,3],
# 
# Your function should return length = 7, with the first seven elements of nums
# being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
# 
# It doesn't matter what values are set beyond the returned length.
# 
# 
# Clarification:
# 
# Confused why the returned value is an integer but your answer is an array?
# 
# Note that the input array is passed in by reference, which means modification
# to the input array will be known to the caller as well.
# 
# Internally you can think of this:
# 
# 
# // nums is passed in by reference. (i.e., without making a copy)
# int len = removeDuplicates(nums);
# 
# // any modification to nums in your function would be known by the caller.
# // using the length returned by your function, it prints the first len
# elements.
# for (int i = 0; i < len; i++) {
# print(nums[i]);
# }
# 
# 
#

# @lc code=start
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ret = 0
        numslen = len(nums)
        start = 0
        end = 0
        count = 0
        base = 0

        while end < numslen:
            if start == end:
                base = nums[start]
                count = 1
            elif start < end:
                if nums[end] == base:
                    if count < 2:
                        start += 1
                        if end != start:
                            nums[start] = nums[end]
                        count += 1
                
                else:
                    start += 1
                    if end != start:
                        nums[start] = nums[end]
                    count = 1
                    base = nums[end]        
            end += 1            
        ret = len(nums[:start+1])
        print(nums[:start+1])

        return ret

if __name__ == "__main__":
    solu = Solution()
    nums = [0,1,2,3]
    ret = solu.removeDuplicates(nums)
    print(ret)
        
# @lc code=end

