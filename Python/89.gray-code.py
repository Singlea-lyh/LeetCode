#
# @lc app=leetcode id=89 lang=python3
#
# [89] Gray Code
#
# https://leetcode.com/problems/gray-code/description/
#
# algorithms
# Medium (48.11%)
# Likes:    660
# Dislikes: 1570
# Total Accepted:    164.3K
# Total Submissions: 334.3K
# Testcase Example:  '2'
#
# The gray code is a binary numeral system where two successive values differ
# in only one bit.
# 
# Given a non-negative integer n representing the total number of bits in the
# code, print the sequence of gray code. A gray code sequence must begin with
# 0.
# 
# Example 1:
# 
# 
# Input: 2
# Output: [0,1,3,2]
# Explanation:
# 00 - 0
# 01 - 1
# 11 - 3
# 10 - 2
# 
# For a given n, a gray code sequence may not be uniquely defined.
# For example, [0,2,3,1] is also a valid gray code sequence.
# 
# 00 - 0
# 10 - 2
# 11 - 3
# 01 - 1
# 
# 
# Example 2:
# 
# 
# Input: 0
# Output: [0]
# Explanation: We define the gray code sequence to begin with 0.
# A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
# 1.
# Therefore, for n = 0 the gray code sequence is [0].
# 
# 
#

# @lc code=start
from typing import List
class Solution:
    def grayCode(self, n: int) -> List[int]:
        # ret = [0]
        # head = 1
        # # print(int("0101", 2))
        # # temp = [0 for _ in range(n)]
        # # print(temp)
        # # elem_to_str = [str(i) for i in temp]
        # # list_to_str = ''.join(elem_to_str)
        # # print(list_to_str)
        # # # ret.append(int(list_to_str, 2))

        # for _ in range(n):
        #     for j in range(len(ret) -  1, -1 , -1):
        #         ret.append(head + ret[j])
        #     head <<= 1

        # return ret

        def recursion(temp, res):
            ret.append(res)
            for i in range(1, temp + 1):
                res ^= (1 << (i - 1))
                recursion(i - 1, res)
            # for i in range(0, temp):
            #     res ^= (1 << i)
            #     recursion(i, res)

        ret = []
        recursion(n, 0)

        return ret
        

if __name__ == "__main__":
    solu = Solution()
    n = 2
    ret = solu.grayCode(n)

    print(ret)
        
# @lc code=end

