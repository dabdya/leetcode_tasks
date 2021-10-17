# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        count = 1
        node = head
        while node.next:
            node = node.next
            count += 1
           
        preceding_rm = head
        iters = count - n - 1
        while iters > 0:
            preceding_rm = preceding_rm.next
            iters -= 1
        
        """Ситуация когда нужно удалить самый первый элемент, т.е. head"""
        if iters == -1:
            return head.next
        
        """Иначе нужно рассмотреть два случая: когда удаляемый элемент последний,
           тогда нужно просто перевести предшествуюший элемент в None,
           и второй случай когда удаляемый элемент в середине - тогда
           просто переходим через одного"""
        if preceding_rm.next.next:
            preceding_rm.next = preceding_rm.next.next
        else: 
            preceding_rm.next = None

        return head