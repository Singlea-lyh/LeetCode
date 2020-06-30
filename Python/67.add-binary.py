#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#
# https://leetcode.com/problems/add-binary/description/
#
# algorithms
# Easy (42.71%)
# Likes:    1735
# Dislikes: 271
# Total Accepted:    445K
# Total Submissions: 1M
# Testcase Example:  '"11"\n"1"'
#
# Given two binary strings, return their sum (also a binary string).
# 
# The input strings are both non-empty and contains only characters 1 or 0.
# 
# Example 1:
# 
# 
# Input: a = "11", b = "1"
# Output: "100"
# 
# Example 2:
# 
# 
# Input: a = "1010", b = "1011"
# Output: "10101"
# 
# 
# Constraints:
# 
# 
# Each string consists only of '0' or '1' characters.
# 1 <= a.length, b.length <= 10^4
# Each string is either "0" or doesn't contain any leading zero.
# 
# 
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # templist = []
        # carrybit = 0

        # alen = len(a)
        # blen = len(b)

        # aidx = alen - 1
        # bidx = blen - 1

        # while aidx >= 0 or bidx >= 0:
        #     abit = a[aidx] if aidx >= 0 else 0
        #     bbit = b[bidx] if bidx >= 0 else 0
        #     temp = int(abit) + int(bbit) + carrybit
        #     carrybit = temp // 2
        #     templist.insert(0, str(temp % 2))
        #     aidx -= 1
        #     bidx -= 1
        # if carrybit:
        #     templist.insert(0, str(carrybit))

        # print(templist)

        # ret = "".join(templist)

        # return ret

        if not a and not b:
           ret = ""
        elif a and not b:
            ret = int(a, 2)
        elif b and not a:
            ret = int(b, 2)
        else:
            ret = '{0:b}'.format(int(a,base = 2) + int(b,base = 2))

        return ret 


if __name__ == "__main__":
    solu = Solution()
    astring = ""
    bstring = ""

    ret = solu.addBinary(astring, bstring) 

    print(ret)
        
# @lc code=end

