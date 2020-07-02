#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#
# https://leetcode.com/problems/climbing-stairs/description/
#
# algorithms
# Easy (46.36%)
# Likes:    4262
# Dislikes: 140
# Total Accepted:    676.8K
# Total Submissions: 1.4M
# Testcase Example:  '2'
#
# You are climbing a stair case. It takes n steps to reach to the top.
# 
# Each time you can either climb 1 or 2 steps. In how many distinct ways can
# you climb to the top?
# 
# Example 1:
# 
# 
# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
# 
# 
# Example 2:
# 
# 
# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 45
# 
# 
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # def fibonacci(n, ret):
        #     # ret = 0
        #     if n == 0:
        #         return 1
        #     elif n == 1:
        #         return 1
        #     ret = fibonacci(n - 1, ret) + fibonacci(n - 2, ret)
        #     return ret

        # ret = 0
        # ret = fibonacci(n, ret)
        # return ret

        ret = 0
        if n == 0 or n == 1:
            return 1
        prenum ,pprenum = 1,1
        curnum = pprenum + prenum
        for _ in range(2, n):
            pprenum = prenum
            prenum = curnum
            curnum = pprenum + prenum
        ret = curnum
        return ret
        

if __name__ == "__main__":
    solu = Solution()
    num = 34
    ret = solu.climbStairs(num)

    print(ret)
        
# @lc code=end

