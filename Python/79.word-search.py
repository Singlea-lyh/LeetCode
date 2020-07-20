#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#
# https://leetcode.com/problems/word-search/description/
#
# algorithms
# Medium (33.93%)
# Likes:    3741
# Dislikes: 183
# Total Accepted:    470.3K
# Total Submissions: 1.3M
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# Given a 2D board and a word, find if the word exists in the grid.
# 
# The word can be constructed from letters of sequentially adjacent cell, where
# "adjacent" cells are those horizontally or vertically neighboring. The same
# letter cell may not be used more than once.
# 
# Example:
# 
# 
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
# 
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
# 
# 
# 
# Constraints:
# 
# 
# board and word consists only of lowercase and uppercase English letters.
# 1 <= board.length <= 200
# 1 <= board[i].length <= 200
# 1 <= word.length <= 10^3
# 
# 
#

# @lc code=start
from  typing import List
from collections import Counter
from collections import defaultdict

class Solution:
    directs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    def exist(self, board: List[List[str]], word: str) -> bool:
        # ret = True
        # count = Counter()
        # defadict = defaultdict(int)

        # if not board:
        #     ret = False
        #     return ret

        # rows = len(board)
        # colus = len(board[0])
        # wordlen = len(word)

        # # for row in range(rows):
        # #     count.update(board[row])
        
        # # print(count)
        # # print(count[E])

        # # deafdict = defaultdict(count)

        # # print(deafdict)

        # for row in range(rows):
        #     for colu in range(colus):
        #         defadict[board[row][colu]] += 1
        
        # # print(defadict)

        # for i in range(wordlen):
        #     c = word[i]
        #     defadict[c] -= 1
        #     if defadict[c] < 0:
        #         ret = False
        #         break
        # # if i == wordlen:
        # #     ret = True

        # return ret
        rows = len(board)
        if rows == 0:
            return False
        colus = len(board[0])

        mark = [[0 for _ in range(rows)] for _ in range(colus)]
        # print(mark)

        for row in range(rows):
            for colu in range(colus):
                if board[row][colu] == word[0]:
                    mark[row][colu] = 1
                    if self.backtrack(board, mark, row, colu, word[1:]) ==  True:
                        return True
                    else:
                        mark[row][colu] = 0
        
        return False


    def backtrack(self, board, mark, row, colu, word):
        if len(word) == 0:
            return True

        for dicret in self.directs:
            cur_row = row + dicret[0]
            cur_colu =colu + dicret[1]

            if cur_row >= 0 and cur_row < len(board) and cur_colu >= 0 and cur_colu < len(board[0]) and board[cur_row][cur_colu] == word[0]:
                if mark[cur_row][cur_colu] == 1:
                    continue
                mark[cur_row][cur_colu] = 1
                if self.backtrack(board, mark, cur_row, cur_colu, word[1:]) == True:
                    return True 
                else:
                    mark[cur_row][cur_colu] = 0
        
        return False

if __name__ == "__main__":
    solu = Solution()
    board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    word = 'ABCCED'
    ret = solu.exist(board, word)
    print(ret)
        
# @lc code=end

