#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#
# https://leetcode.com/problems/jump-game/description/
#
# algorithms
# Medium (33.36%)
# Likes:    4091
# Dislikes: 322
# Total Accepted:    464.3K
# Total Submissions: 1.4M
# Testcase Example:  '[2,3,1,1,4]'
#
# Given an array of non-negative integers, you are initially positioned at the
# first index of the array.
# 
# Each element in the array represents your maximum jump length at that
# position.
# 
# Determine if you are able to reach the last index.
# 
# 
# Example 1:
# 
# 
# Input: nums = [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
# 
# 
# Example 2:
# 
# 
# Input: nums = [3,2,1,0,4]
# Output: false
# Explanation: You will always arrive at index 3 no matter what. Its maximum
# jump length is 0, which makes it impossible to reach the last index.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= nums.length <= 3 * 10^4
# 0 <= nums[i][j] <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def canJump(self, nums: list) -> bool:
        ret = False
        local = 0
        maxlocal = 0
        numlen = len(nums)

        for idx in range(numlen):
            # if idx == local:
            #     maxlocal = (idx + nums[idx]) if ((idx + nums[idx]) > maxlocal) else maxlocal
            #     local = maxlocal
            # elif idx > local:
            #     ret = False
            # else:
            #     maxlocal = (idx + nums[idx]) if ((idx + nums[idx]) > maxlocal) else maxlocal
            #     continue
            if idx <= maxlocal:
                maxlocal = max(maxlocal, idx + nums[idx])
                if maxlocal >= numlen - 1:
                    ret = True
        
        # if maxlocal >= numlen - 1:
        #     ret = True
                
        return ret


if __name__ == "__main__":
    solu = Solution()
    nums =[2,5,0,0]
    ret = solu.canJump(nums)

    if ret:
        print("True")
    else:
        print("False")
        
# @lc code=end

