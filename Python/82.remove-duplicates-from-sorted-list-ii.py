#
# @lc app=leetcode id=82 lang=python3
#
# [82] Remove Duplicates from Sorted List II
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
#
# algorithms
# Medium (35.59%)
# Likes:    1713
# Dislikes: 109
# Total Accepted:    252.2K
# Total Submissions: 688.8K
# Testcase Example:  '[1,2,3,3,4,4,5]'
#
# Given a sorted linked list, delete all nodes that have duplicate numbers,
# leaving only distinct numbers from the original list.
# 
# Return the linked list sorted as well.
# 
# Example 1:
# 
# 
# Input: 1->2->3->3->4->4->5
# Output: 1->2->5
# 
# 
# Example 2:
# 
# 
# Input: 1->1->1->2->3
# Output: 2->3
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
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # ret = None
        # if not head:
        #     return ret
        
        # node = head
        # index = head
        # base = node.val
        # count = 1

        # while node.next:
        #     temp = node.next
        #     if base == temp.val:
        #         node = node.next
        #         count += 1
        #     else:
        #         if count == 1:
        #             node.next = None
        #             if ret == None:
        #                 ret = node
        #                 index = node
        #             else:
        #                 index.next = node
        #                 index = index.next
        #         base = temp.val
        #         count = 1
        #     node = temp
        
        # if count == 1:
        #     if not ret:
        #         ret = node
        #     else:
        #         index.next = node
        # return ret

        ret = None
        if not head:
            return ret
        
        slow = head
        quick = head
        index = head

        while quick.next != None:
            if quick.val != quick.next.val:
                if slow == quick:
                    if ret == None:
                        # slow.next = None
                        ret = slow
                        index = slow
                    else:
                        index.next = slow
                        index = index.next
                slow = quick.next
            quick = quick.next
        
        if slow == quick:
            if ret == None:
                ret = quick
            else:
                index.next = quick
        else:
            index.next = None
    
        return ret    


if __name__ == "__main__":
    solu = Solution()
    # five = ListNode(5)
    # four2 = ListNode(4, next = five)
    # four1 = ListNode(4, next = four2)
    # three2 = ListNode(3, next = four1)
    # three1 = ListNode(2, three2)
    three1 = ListNode(2)
    two = ListNode(2, three1)
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

