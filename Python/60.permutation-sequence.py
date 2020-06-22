#
# @lc app=leetcode id=60 lang=python3
#
# [60] Permutation Sequence
#
# https://leetcode.com/problems/permutation-sequence/description/
#
# algorithms
# Medium (35.51%)
# Likes:    1462
# Dislikes: 317
# Total Accepted:    181.8K
# Total Submissions: 496.8K
# Testcase Example:  '3\n3'
#
# The set [1,2,3,...,n] contains a total of n! unique permutations.
# 
# By listing and labeling all of the permutations in order, we get the
# following sequence for n = 3:
# 
# 
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
# 
# 
# Given n and k, return the k^th permutation sequence.
# 
# Note:
# 
# 
# Given n will be between 1 and 9 inclusive.
# Given k will be between 1 and n! inclusive.
# 
# 
# Example 1:
# 
# 
# Input: n = 3, k = 3
# Output: "213"
# 
# 
# Example 2:
# 
# 
# Input: n = 4, k = 9
# Output: "2314"
# 
# 
#

# @lc code=start
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # ret = []
        # initstr = ""
        
        # for i in range(1, n + 1):
        #     initstr += str(i) 
        # ret.append(initstr)
        
        # # print(ret)

        # for _ in  range(1, k):
        #     temp = list(ret[-1])
        #     numlen = len(temp)
        #     end = numlen - 1

        #     while end > 0 and temp[end] < temp[end - 1]:
        #         end -= 1
        #         # rightmin = rightmin if min(temp[rightmin], temp[end]) == temp[rightmin] else end
        #     start = end - 1
        #     rightmin = end
        #     for idx in range(end, numlen):
        #         if temp[idx] > temp[start] and temp[idx] < temp[rightmin]:
        #             rightmin = idx
                    
        #     temp[start], temp[rightmin] = temp[rightmin], temp[start] 
        #     # print(start, end)

        #     part = temp[end:numlen]
        #     part.sort()
        #     temp[end:numlen] = part
        #     # print(temp[end:numlen])
            
        #     ret.append(''.join(temp))  

        # return ret[-1]

        factorials, nums = [1], ["1"]
        for i in range(1, n):
            factorials.append(factorials[i - 1] * i)
            nums.append(str(i + 1))
        
        print(factorials, nums)

        k -= 1 

        ret = []

        for i in range(n-1, -1, -1):
            idx = k // factorials[i]
            k -= idx * factorials[i]

            ret.append(nums[idx])
            del(nums[idx])
        
        return "".join(ret)

if __name__ == "__main__":
    solu = Solution()
    ret = solu.getPermutation(3, 3)
    print(ret)
        
# @lc code=end

