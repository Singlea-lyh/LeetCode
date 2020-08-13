#
# @lc app=leetcode id=88 lang=python3
#
# [88] Merge Sorted Array
#
# https://leetcode.com/problems/merge-sorted-array/description/
#
# algorithms
# Easy (38.40%)
# Likes:    2393
# Dislikes: 4284
# Total Accepted:    625K
# Total Submissions: 1.6M
# Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
#
# Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
# one sorted array.
# 
# Note:
# 
# 
# The number of elements initialized in nums1 and nums2 are m and n
# respectively.
# You may assume that nums1 has enough space (size that is equal to m + n) to
# hold additional elements from nums2.
# 
# 
# Example:
# 
# 
# Input:
# nums1 = [1,2,3,0,0,0], m = 3
# nums2 = [2,5,6],       n = 3
# 
# Output: [1,2,2,3,5,6]
# 
# 
# 
# Constraints:
# 
# 
# -10^9 <= nums1[i], nums2[i] <= 10^9
# nums1.length == m + n
# nums2.length == n
# 
# 
#

# @lc code=start
from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        ret = []
        end = m + n - 1
        idxs1 = m - 1
        idxs2 = n - 1

        while idxs1 >= 0 or idxs2 >= 0:
            if idxs1 < 0:
                while idxs2 >= 0:
                    nums1[end] = nums2[idxs2]
                    idxs2 -= 1
                    end -= 1
                break
            elif idxs2 < 0:
                break
            else:
                nums1[end] = nums1[idxs1] if nums1[idxs1] >= nums2[idxs2] else nums2[idxs2]
                if nums1[idxs1] >= nums2[idxs2]:
                    idxs1 -= 1
                else:
                    idxs2 -= 1
                end -= 1
        ret = nums1

        return ret

if __name__ == "__main__":
    solu = Solution()
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3

    ret = solu.merge(nums1, m, nums2, n)
    print(ret)

        
# @lc code=end

