#
# @lc app=leetcode id=61 lang=python3
#
# [61] Rotate List
#
# https://leetcode.com/problems/rotate-list/description/
#
# algorithms
# Medium (29.10%)
# Likes:    1168
# Dislikes: 988
# Total Accepted:    267.3K
# Total Submissions: 901.7K
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# Given a linked list, rotate the list to the right by k places, where k is
# non-negative.
# 
# Example 1:
# 
# 
# Input: 1->2->3->4->5->NULL, k = 2
# Output: 4->5->1->2->3->NULL
# Explanation:
# rotate 1 steps to the right: 5->1->2->3->4->NULL
# rotate 2 steps to the right: 4->5->1->2->3->NULL
# 
# 
# Example 2:
# 
# 
# Input: 0->1->2->NULL, k = 4
# Output: 2->0->1->NULL
# Explanation:
# rotate 1 steps to the right: 2->0->1->NULL
# rotate 2 steps to the right: 1->2->0->NULL
# rotate 3 steps to the right: 0->1->2->NULL
# rotate 4 steps to the right: 2->0->1->NULL
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        # ret = None
        # listlen = 0
        # rotatenum = 0

        # if head == None:
        #     return None

        # temp = head
        # tail = None
        # while temp != None:
        #     listlen += 1
        #     tail = temp
        #     temp = temp.next

        
        # print(listlen)
        # rotatenum = k % listlen

        # if rotatenum == 0:
        #     return head

        # idx = 0
        # temp = head
        # while idx < (listlen - rotatenum - 1):
        #     temp = temp.next
        #     idx += 1
        # newhead = temp.next
        
        # tail.next, temp.next = head, tail.next
        # ret = newhead

        # return ret

        ret = None
        listlen = 0
        
        if head == None:
            return head
        
        temp = head
        
        while temp.next != None:
            temp = temp.next
            listlen += 1
        listlen += 1
       
        rotatenum = k % listlen
        if rotatenum == 0:
            return head
        
        temp.next = head

        temp = head
        idx = 0
        while idx < (listlen - rotatenum - 1):
            temp = temp.next
            idx += 1

        ret = temp.next
        temp.next = None

        return ret

if __name__ == "__main__":
    solu = Solution()
    head = None
    for i in range(2, -1, -1):
        temp = ListNode(i,head)
        # temp.next = head
        head = temp
    
    temp = head

    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print("NULL")

    ret = solu.rotateRight(head, 4)

    temp = ret
    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print("NULL")



# @lc code=end

