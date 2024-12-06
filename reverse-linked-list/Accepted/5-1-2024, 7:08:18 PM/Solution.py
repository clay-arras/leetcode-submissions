// https://leetcode.com/problems/reverse-linked-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = head

        prev = None
        curr = head
        while curr != None:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            
        return prev
        