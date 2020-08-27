#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (37.57%)
# Likes:    2589
# Dislikes: 149
# Total Accepted:    284.1K
# Total Submissions: 728.2K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Reverse a linked list from position m to n. Do it in one-pass.
# 
# Note: 1 ≤ m ≤ n ≤ length of list.
# 
# Example:
# 
# 
# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import List

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n or head == None:
            return head

        cur = head
        pre = None
        start = None
        idx = 0
        while cur != None:
            idx += 1
            if idx == m:
                start = cur
                break
            pre = cur
            cur = cur.next

        if start == None:
            return head
        
        while cur.next != None:
            behind = cur.next
            if pre != None:
                temp = pre.next
                pre.next = behind
                cur.next = behind.next
                behind.next = temp
                # cur = cur 
            else:
                temp = head
                cur.next = behind.next
                behind.next = temp
                head = behind


            idx += 1 
            if idx == n:
                break 

        return head

if __name__ == "__main__":
    solu = Solution()
    five = ListNode(5)
    four = ListNode(4, five)
    three = ListNode(3, four)
    two = ListNode(2, three)
    head = ListNode(1, two)

    m = 1
    n = 3
    temp = head
    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print(None)

    ret = solu.reverseBetween(head, m, n)

    temp = ret
    while temp != None:
        print(temp.val, end = "->")
        temp = temp.next
    print(None)


        
# @lc code=end

