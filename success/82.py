# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
        
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        res = head
        prev = None
        
        while head and head.next:
            nxt = head.next
            if head.val == nxt.val:
                
                while nxt and head.val == nxt.val:
                    nxt = nxt.next
                
                if not prev:
                    head = nxt
                    res = head
                else:
                    head = prev
                    head.next = nxt
            else:
                prev = head
                head = head.next
        
        return res