#
# @lc app=leetcode id=83 lang=python3
#
# [83] Remove Duplicates from Sorted List
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#
# algorithms
# Easy (44.52%)
# Likes:    1577
# Dislikes: 112
# Total Accepted:    468.7K
# Total Submissions: 1M
# Testcase Example:  '[1,1,2]'
#
# Given a sorted linked list, delete all duplicates such that each element
# appear only once.
# 
# Example 1:
# 
# 
# Input: 1->1->2
# Output: 1->2
# 
# 
# Example 2:
# 
# 
# Input: 1->1->2->3->3
# Output: 1->2->3
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # ret = None
        # if not head:
        #     return ret

        # ret = head

        # start = head
        # end = head

        # while end.next != None:
        #     if end.val != end.next.val:
        #         if start != end:
        #             start.next = end.next
        #         start = end.next
        #     end = end.next
        
        # end.next = None            

        # return ret

        ret = None 
        if not head:
            return ret
        ret = head
        current = head

        while current.next != None:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
            
        current.next = None

        return ret

if __name__ == "__main__":
    solu = Solution()
    five = ListNode(5)
    four2 = ListNode(5, next = five)
    four1 = ListNode(4, next = four2)
    three2 = ListNode(3, next = four1)
    three1 = ListNode(2, three2)
    # three1 = ListNode(2)
    two = ListNode(1, three1)
    head = ListNode(1, two)

    temp = head
    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print()

    ret = solu.deleteDuplicates(head)

    temp = ret
    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print()


        
# @lc code=end

