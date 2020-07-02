#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#
# https://leetcode.com/problems/sqrtx/description/
#
# algorithms
# Easy (33.09%)
# Likes:    1302
# Dislikes: 1881
# Total Accepted:    549K
# Total Submissions: 1.6M
# Testcase Example:  '4'
#
# Implement int sqrt(int x).
# 
# Compute and return the square root of x, where x is guaranteed to be a
# non-negative integer.
# 
# Since the return type is an integer, the decimal digits are truncated and
# only the integer part of the result is returned.
# 
# Example 1:
# 
# 
# Input: 4
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since 
# the decimal part is truncated, 2 is returned.
# 
# 
#

# @lc code=start
import math
class Solution:
    def mySqrt(self, x: int) -> int:
        # ret = 0
        # idx = 1

        # product = idx * idx

        # while product <= x:
        #     idx += 1
        #     product = idx * idx
        
        # ret = idx - 1

        # return ret 

        # ret = 0
        # if x == 0:
        #     return ret
        # ret = int(math.exp(0.5 * math.log(x)))
        # return (ret + 1) if (ret + 1) ** 2 <= x else ret


        # ret = 0
        # start, end = 0, x - 1
        # while start < end:
        #     mid = (start + end) // 2
        #     if mid * mid <= x:
        #         ret = mid
        #         start = mid + 1
        #     else:
        #         end = mid - 1

        # return ret 

        ret = 0
        if x == 0:
            return 0
        
        C, x0 = float(x), float(x)
        while True:
            xi = 0.5 * (x0 + C / x0)
            if abs(x0 - xi) < 1e-7:
                break
            x0 = xi
        ret = x0
        
        return int(ret)



if __name__ == "__main__":
    solu = Solution()
    num = 8
    ret = solu.mySqrt(num)
    print(ret)
        
# @lc code=end

