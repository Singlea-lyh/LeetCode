#
# @lc app=leetcode id=77 lang=python3
#
# [77] Combinations
#
# https://leetcode.com/problems/combinations/description/
#
# algorithms
# Medium (52.58%)
# Likes:    1474
# Dislikes: 66
# Total Accepted:    290.1K
# Total Submissions: 534.6K
# Testcase Example:  '4\n2'
#
# Given two integers n and k, return all possible combinations of k numbers out
# of 1 ... n.
# 
# Example:
# 
# 
# Input: n = 4, k = 2
# Output:
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
# 
# 
#

# @lc code=start
from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # ret = []
        # tempret = []
        # if n < k:
        #     ret.append([])
        #     return ret
        
        # for i in range(1, k + 1):
        #     tempret.append(i)
        
        # print(tempret)
        # ret.append(tempret)

        # for i in range(k + 1, n + 1):
        #     for temp in ret:
        #         for j in range(k):
        #             templist = temp[:]
        #             templist[j] = i
        #             tempset = set(templist)
        #             if len(tempset) != k:
        #                 continue
        #             templist = list(tempset)
        #             if templist not in ret:
        #                 ret.append(templist)

        # return ret 


        # def backtrack(start, pre):
        #     if len(pre) == k:
        #         ret.append(pre[:])
        #         return 
            
        #     for i in range(start, n - (k - len(pre)) + 2):
        #         pre.append(i)
        #         backtrack(i + 1, pre)
        #         pre.pop()


        # ret = []
        # pre = []
        # if n < k:
        #     return ret.append([])
        # backtrack(1, pre)

        # return ret

        nums = list(range(1, k + 1)) + [n + 1]

        print(nums)
        
        output, j = [], 0
        while j < k:
            output.append(nums[:k])
            print(output)
 
            j = 0
            while j < k and nums[j + 1] == nums[j] + 1:
                nums[j] = j + 1
                j += 1
            nums[j] += 1
            
        return output


if __name__ == "__main__":
    solu = Solution()
    num  = 4
    knum = 3
    ret = solu.combine(num, knum)
    print(ret)
        
# @lc code=end

