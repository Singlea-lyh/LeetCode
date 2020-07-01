#
# @lc app=leetcode id=68 lang=python3
#
# [68] Text Justification
#
# https://leetcode.com/problems/text-justification/description/
#
# algorithms
# Hard (26.43%)
# Likes:    663
# Dislikes: 1560
# Total Accepted:    135.1K
# Total Submissions: 494.2K
# Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
#
# Given an array of words and a width maxWidth, format the text such that each
# line has exactly maxWidth characters and is fully (left and right)
# justified.
# 
# You should pack your words in a greedy approach; that is, pack as many words
# as you can in each line. Pad extra spaces ' ' when necessary so that each
# line has exactly maxWidth characters.
# 
# Extra spaces between words should be distributed as evenly as possible. If
# the number of spaces on a line do not divide evenly between words, the empty
# slots on the left will be assigned more spaces than the slots on the right.
# 
# For the last line of text, it should be left justified and no extra space is
# inserted between words.
# 
# Note:
# 
# 
# A word is defined as a character sequence consisting of non-space characters
# only.
# Each word's length is guaranteed to be greater than 0 and not exceed
# maxWidth.
# The input array words contains at least one word.
# 
# 
# Example 1:
# 
# 
# Input:
# words = ["This", "is", "an", "example", "of", "text", "justification."]
# maxWidth = 16
# Output:
# [
# "This    is    an",
# "example  of text",
# "justification.  "
# ]
# 
# 
# Example 2:
# 
# 
# Input:
# words = ["What","must","be","acknowledgment","shall","be"]
# maxWidth = 16
# Output:
# [
# "What   must   be",
# "acknowledgment  ",
# "shall be        "
# ]
# Explanation: Note that the last line is "shall be    " instead of "shall
# be",
# because the last line must be left-justified instead of fully-justified.
# ⁠            Note that the second line is also left-justified becase it
# contains only one word.
# 
# 
# Example 3:
# 
# 
# Input:
# words =
# ["Science","is","what","we","understand","well","enough","to","explain",
# "to","a","computer.","Art","is","everything","else","we","do"]
# maxWidth = 20
# Output:
# [
# "Science  is  what we",
# ⁠ "understand      well",
# "enough to explain to",
# "a  computer.  Art is",
# "everything  else  we",
# "do                  "
# ]
# 
# 
#

# @lc code=start
class Solution:
    def fullJustify(self, words: list, maxWidth: int) -> list:
        ret = []
        line = []
        wordslen = len(words)
        idx = 0
        curlinenum = 0
        totalwordlen = 0
        templine = []
        wordnum = 0

        while idx < wordslen:
            curwordlen = len(words[idx])
            curlinenum += curwordlen
            if curlinenum <= maxWidth:
                line.append(words[idx])
                totalwordlen += curwordlen
                wordnum += 1
                curlinenum += 1
                idx += 1
            else:
                if wordnum == 1:
                    addspace = [' '] * (maxWidth - totalwordlen)
                    templine =line + addspace
                else:
                    spacelen = maxwidth - totalwordlen
                    wordspace = spacelen // (wordnum - 1)
                    spacerest = spacelen % (wordnum - 1)
                    wordidx = 0

                    while wordidx < wordnum:
                        if wordidx == wordnum - 1:
                            templine.append(line[wordidx])
                            break
                        templine.append(line[wordidx])
                        tempspace = wordspace
                        if spacerest > 0:
                            tempspace += 1
                            spacerest -= 1
                        
                        addspace = [' ' for _ in range(tempspace)]
                        templine += addspace
                        wordidx += 1
                ret.append(''.join(templine))
                line.clear()
                templine.clear()
                wordnum = 0
                curlinenum = 0
                totalwordlen = 0
            
        if wordnum != 0:
            addspace = [' ' for _ in range(maxWidth - curlinenum)]
            if addspace:
                line.append(''.join(addspace))
            else:
                if wordnum == 1 and totalwordlen < maxWidth:
                    line.append('')
            print(line)
            ret.append(' '.join(line))
        
        return ret


if __name__ == "__main__":
    solu = Solution()
    words = ["a"]
    maxwidth =2

    ret = solu.fullJustify(words, maxwidth)

    print(ret)

    tempstring = 'aa'
    print(tempstring)
    print(id(tempstring))
    tempstring += "nn"
    print(tempstring)
    print(id(tempstring))




# @lc code=end

