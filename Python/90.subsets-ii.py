#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#
# https://leetcode.com/problems/subsets-ii/description/
#
# algorithms
# Medium (45.60%)
# Likes:    1747
# Dislikes: 75
# Total Accepted:    287.5K
# Total Submissions: 609.6K
# Testcase Example:  '[1,2,2]'
#
# Given a collection of integers that might contain duplicates, nums, return
# all possible subsets (the power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: [1,2,2]
# Output:
# [
# ⁠ [2],
# ⁠ [1],
# ⁠ [1,2,2],
# ⁠ [2,2],
# ⁠ [1,2],
# ⁠ []
# ]
# 
# 
#

# @lc code=start
from typing  import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []

        return ret


if __name__ == "__main__":
    ret = Solution()
    nums = [1,2,2]
    ret = ret.subsetsWithDup(nums)
    print(ret) 
# @lc code=end

