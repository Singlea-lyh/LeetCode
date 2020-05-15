"""
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 
限制：
2 <= n <= 100000
"""

class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        length = len(nums)
        i = 0

        while i < length:
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
                 return nums[i]
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]

    def findRepeatNumberCounter(self, nums): 
        from collections import Counter   
        NumsCounter = Counter(nums) 
        print(type(NumsCounter)) 
        NumsDict = dict(NumsCounter)
        print(NumsDict)
        for k, v in NumsCounter.items():
            if v > 1:
                return k        
           

if __name__ == "__main__":
    nums = [2, 3, 1, 0, 2, 5, 3]
    repeatnum = Solution()
    print(repeatnum.findRepeatNumber(nums))
    print(repeatnum.findRepeatNumberCounter(nums))
            
