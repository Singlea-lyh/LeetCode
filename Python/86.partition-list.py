#
# @lc app=leetcode id=86 lang=python3
#
# [86] Partition List
#
# https://leetcode.com/problems/partition-list/description/
#
# algorithms
# Medium (40.07%)
# Likes:    1337
# Dislikes: 303
# Total Accepted:    218.6K
# Total Submissions: 528.1K
# Testcase Example:  '[1,4,3,2,5,2]\n3'
#
# Given a linked list and a value x, partition it such that all nodes less than
# x come before nodes greater than or equal to x.
# 
# You should preserve the original relative order of the nodes in each of the
# two partitions.
# 
# Example:
# 
# 
# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing  import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # ret  = None
        # start = ListNode(0)
        # end = ListNode(0)
        # # index = head

        # while end != None:
        #     temp = end.next
        #     end.next = None
        #     if end.val < x:
        #         if start == head:
        #             ret = head
        #             ret.next = start
        #             start = ret
        #         else:
        #             temp1 =start.next
        #             start.next = end
        #             start = end
        #             start.next = temp1

        #     end = temp

        # return ret

        before = before_head = ListNode(0)
        after = after_head = ListNode(0)

        while head:

            if head.val < x:
                before.next = head
                before = before.next
            else:
                after.next = head
                after = after.next

            head = head.next


        after.next = None
        before.next = after_head.next

        return before_head.next

if __name__ == "__main__":
    solu  = Solution()
    one = ListNode(2)
    two = ListNode(5, one)
    three = ListNode(2, two)
    four = ListNode(3, three)
    five = ListNode(4, four)
    head = ListNode(1, five)

    x = 3

    temp = head 
    while temp:
        print(temp.val, end = "->")
        temp = temp.next
    print()

    ret = solu.partition(head, x)

    temp = ret 
    
    while temp:
        print(temp.val, end = "->")
        temp = temp.next
    print()
        
# @lc code=end

