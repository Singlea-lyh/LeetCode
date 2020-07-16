#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#
# https://leetcode.com/problems/subsets/description/
#
# algorithms
# Medium (58.56%)
# Likes:    3859
# Dislikes: 83
# Total Accepted:    589.8K
# Total Submissions: 959.1K
# Testcase Example:  '[1,2,3]'
#
# Given a set of distinct integers, nums, return all possible subsets (the
# power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: nums = [1,2,3]
# Output:
# [
# ⁠ [3],
# [1],
# [2],
# [1,2,3],
# [1,3],
# [2,3],
# [1,2],
# []
# ]
# 
#

# @lc code=start

from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # def backtrack(idx, pre, k, numlen):
        #     if len(pre) == k:
        #         ret.append(pre[:])
        #         return 

        #     for num in range(idx, numlen):
        #         pre.append(nums[num])
        #         backtrack(num + 1, pre, k, numlen)
        #         pre.pop()

        # def combinations(numlen, k):
        #     pre = []
        #     backtrack(0, pre, k, numlen)
        
        # ret = []
        # ret.append([])
        # numlen = len(nums)
        # if numlen < 1:
        #     return ret
        
        # # for num in nums:
        # #     ret.append([num])
        # # print(ret)

        # for k in range(1, numlen + 1):
        #     combinations(numlen, k)

        # return ret 


        # def combinations(numlen, k):
        #     idx = []
        #     for i in range(k):
        #         idx.append(i)
        #     idx.append(numlen)

        #     left = 0

        #     while left < k:
        #         tempret = []
        #         for i in idx[:k]:
        #             tempret.append(nums[i])
        #         ret.append(tempret)

        #         left = 0
        #         while left < k and idx[left + 1] == idx[left] + 1:
        #             idx[left] = left
        #             left += 1
        #         idx[left] += 1

        # ret = []
        # ret.append([])
        # numlen = len(nums)
        # if numlen < 1:
        #     return ret

        # # combinations(numlen, 2)
        
        # for k in range(1, numlen + 1):
        #     combinations(numlen, k)

        # return ret 

        n = len(nums)
        output = []
        
        # for i in range(2**n, 2**(n + 1)):
        #     # generate bitmask, from 0..00 to 1..11
        #     print(i)
        #     bitmask = bin(i)[3:]
        #     print(bitmask)

        nth_bit = 1 << n
        print(nth_bit)
        for i in range(2**n):
            # generate bitmask, from 0..00 to 1..11
            print(i | nth_bit)
            bitmask = bin(i | nth_bit)[3:]
            print(bitmask)

            
            # append subset corresponding to that bitmask
            output.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        
        return output


if __name__ == "__main__":
    solu = Solution()
    nums = [1,2,3, 4]
    ret = solu.subsets(nums)

    print(ret)
        
# @lc code=end

