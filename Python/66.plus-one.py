#
# @lc app=leetcode id=66 lang=python3
#
# [66] Plus One
#
# https://leetcode.com/problems/plus-one/description/
#
# algorithms
# Easy (41.96%)
# Likes:    1475
# Dislikes: 2339
# Total Accepted:    594.8K
# Total Submissions: 1.4M
# Testcase Example:  '[1,2,3]'
#
# Given a non-empty array of digits representing a non-negative integer, plus
# one to the integer.
# 
# The digits are stored such that the most significant digit is at the head of
# the list, and each element in the array contain a single digit.
# 
# You may assume the integer does not contain any leading zero, except the
# number 0 itself.
# 
# Example 1:
# 
# 
# Input: [1,2,3]
# Output: [1,2,4]
# Explanation: The array represents the integer 123.
# 
# 
# Example 2:
# 
# 
# Input: [4,3,2,1]
# Output: [4,3,2,2]
# Explanation: The array represents the integer 4321.
# 
#

# @lc code=start
class Solution:
    def plusOne(self, digits: list) -> list:
        ret = []
        carrybit = 0
        diglen = len(digits)

        idx = diglen - 1

        while idx >= 0:
            if idx == diglen - 1:
                temp = digits[idx] + 1
            else:
                 temp = digits[idx] + carrybit
            carrybit = temp // 10
            if temp > 9:
                digits[idx] = temp % 10
            else:
                digits[idx] = temp
                break
            idx -= 1
        if idx < 0 and carrybit:
            ret = [carrybit] + digits
        else:
            ret = digits

        return ret



if __name__ == "__main__":
    solu = Solution()
    ditits = [9,9,8]

    ret = solu.plusOne(ditits)

    print(ret)
        
# @lc code=end

