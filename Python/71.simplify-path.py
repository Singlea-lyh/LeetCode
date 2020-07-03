#
# @lc app=leetcode id=71 lang=python3
#
# [71] Simplify Path
#
# https://leetcode.com/problems/simplify-path/description/
#
# algorithms
# Medium (31.40%)
# Likes:    795
# Dislikes: 1770
# Total Accepted:    209.3K
# Total Submissions: 648.1K
# Testcase Example:  '"/home/"'
#
# Given an absolute path for a file (Unix-style), simplify it. Or in other
# words, convert it to the canonical path.
# 
# In a UNIX-style file system, a period . refers to the current directory.
# Furthermore, a double period .. moves the directory up a level.
# 
# Note that the returned canonical path must always begin with a slash /, and
# there must be only a single slash / between two directory names. The last
# directory name (if it exists) must not end with a trailing /. Also, the
# canonical path must be the shortest string representing the absolute
# path.
# 
# 
# 
# Example 1:
# 
# 
# Input: "/home/"
# Output: "/home"
# Explanation: Note that there is no trailing slash after the last directory
# name.
# 
# 
# Example 2:
# 
# 
# Input: "/../"
# Output: "/"
# Explanation: Going one level up from the root directory is a no-op, as the
# root level is the highest level you can go.
# 
# 
# Example 3:
# 
# 
# Input: "/home//foo/"
# Output: "/home/foo"
# Explanation: In the canonical path, multiple consecutive slashes are replaced
# by a single one.
# 
# 
# Example 4:
# 
# 
# Input: "/a/./b/../../c/"
# Output: "/c"
# 
# 
# Example 5:
# 
# 
# Input: "/a/../../b/../c//.//"
# Output: "/c"
# 
# 
# Example 6:
# 
# 
# Input: "/a//b////c/d//././/.."
# Output: "/a/b/c"
# 
# 
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        # retlist = []
        # pathlen = len(path)
        # start = 1
        # end = 1
        # if pathlen == 0:
        #     return '/'

        # while end < pathlen:
        #     if path[end] == '/':
        #         temp = path[start:end]
        #         if temp == '..':
        #             if(len(retlist) > 0):
        #                 del retlist[-1]
        #         elif temp == '.' or temp == '/' or not temp:
        #             pass
        #         else:
        #             retlist.append('/' + temp)
        #         end += 1
        #         start = end
        #     else:
        #         end += 1
        
        # if end != start:
        #     temp = path[start:end]
        #     if temp == '.':
        #         pass
        #     elif temp == '..':
        #         if(len(retlist) > 0):
        #             del retlist[-1]
        #     else:
        #         retlist.append('/' + temp)
        # if not retlist:
        #     retlist = ['/']

        # ret = "".join(retlist)      
        # return ret

        retlist = []
        tuplelist = ('.', '')

        listsplit = path.split('/')
        print(listsplit)
        splitlen = len(listsplit)
        for idx in range(splitlen):
            if listsplit[idx] == '..':
                if len(retlist) > 0:
                    del retlist[-1]
            elif listsplit[idx] not in tuplelist:
                retlist.append(listsplit[idx])
            else:
                pass

        ret = '/' + '/'.join(retlist)        

        return ret

if __name__ == "__main__":
    solu = Solution()
    path = "/a/./b/../../c//////"
    ret = solu.simplifyPath(path)

    print(ret)
        
# @lc code=end

