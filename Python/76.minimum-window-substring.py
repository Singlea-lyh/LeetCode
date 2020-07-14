#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#
# https://leetcode.com/problems/minimum-window-substring/description/
#
# algorithms
# Hard (33.61%)
# Likes:    4470
# Dislikes: 307
# Total Accepted:    396.9K
# Total Submissions: 1.2M
# Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
#
# Given a string S and a string T, find the minimum window in S which will
# contain all the characters in T in complexity O(n).
# 
# Example:
# 
# 
# Input: S = "ADOBECODEBANC", T = "ABC"
# Output: "BANC"
# 
# 
# Note:
# 
# 
# If there is no such window in S that covers all characters in T, return the
# empty string "".
# If there is such window, you are guaranteed that there will always be only
# one unique minimum window in S.
# 
# 
#

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ret = ""
        solve = False
        slen = len(s)
        if slen == 0:
            return ret

        from collections import defaultdict
        left = 0

        needdict = defaultdict(int)

        for c in t:
            needdict[c] += 1
        needcnt = len(t)
        # print(needdict)
        res = (0, float('inf'))

        for right ,c in enumerate(s):
            if needdict[c] > 0:
                needcnt -= 1
            needdict[c] -= 1
            if needcnt == 0:
                while True:
                    c = s[left]
                    if needdict[c] == 0:
                        break
                    needdict[c] += 1
                    left += 1
                if right - left < res[1] - res[0]:
                    res = (left, right)
                needdict[s[left]] += 1
                needcnt += 1
                left += 1
        ret = '' if res[1] > slen else s[res[0]:res[1] + 1]
            
        return ret

if __name__ == "__main__":
    solu = Solution()
    soustr = "ADOBECODEBANC"
    substr = "ABC"
    ret = solu.minWindow(soustr, substr)
    print(ret)
        
# @lc code=end

