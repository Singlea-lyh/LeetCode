#
# @lc app=leetcode id=65 lang=python3
#
# [65] Valid Number
#
# https://leetcode.com/problems/valid-number/description/
#
# algorithms
# Hard (14.86%)
# Likes:    724
# Dislikes: 4744
# Total Accepted:    168.2K
# Total Submissions: 1.1M
# Testcase Example:  '"0"'
#
# Validate if a given string can be interpreted as a decimal number.
# 
# Some examples:
# "0" => true
# " 0.1 " => true
# "abc" => false
# "1 a" => false
# "2e10" => true
# " -90e3   " => true
# " 1e" => false
# "e3" => false
# " 6e-1" => true
# " 99e2.5 " => false
# "53.5e93" => true
# " --6 " => false
# "-+3" => false
# "95a54e53" => false
# 
# Note: It is intended for the problem statement to be ambiguous. You should
# gather all requirements up front before implementing one. However, here is a
# list of characters that can be in a valid decimal number:
# 
# 
# Numbers 0-9
# Exponent - "e"
# Positive/negative sign - "+"/"-"
# Decimal point - "."
# 
# 
# Of course, the context of these characters also matters in the input.
# 
# Update (2015-02-10):
# The signature of the C++ function had been updated. If you still see your
# function signature accepts a const char * argument, please click the reload
# button to reset your code definition.
# 
#

# @lc code=start
class Solution:
    def isNumber(self, s: str) -> bool:
        ret = False
        string = s.strip()
        # print(string)
        strlen = len(string)
        # head = ["+", "-", "."] + [str(i)  for i in range(10)]
        numbers = [str(i)  for i in range(10)]
        # print(head)

        if strlen == 0:
            return ret

        num_show_up , e_show_up, dot_show_up, num_show_e = False, False,False,False

        for idx in range(strlen):
            if string[idx] in numbers:
                num_show_up = True
                num_show_e = True
            elif string[idx] in ('+', '-'):
                if idx > 0 and string[idx - 1] != 'e':
                    return False
            elif string[idx] == '.':
                if dot_show_up or e_show_up:
                    return False
                dot_show_up = True
            elif string[idx] == 'e':
                if e_show_up or not num_show_up:
                    return False
                e_show_up = True
                num_show_up = False
            else:
                return False
            
        ret = num_show_up and num_show_e            
            
        return ret

if __name__ == "__main__":
    solu = Solution()
    string  =  " 1123  "
    ret = solu.isNumber(string)

    print(ret)
        
# @lc code=end

