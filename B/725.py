class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

        
class Solution:
    def splitListToParts(self, head, k: int):
        
        n = 0
        temp = head
        
        while temp:
            n += 1
            temp = temp.next
            
        iters1, count1 = n%k, n//k+1
        iters2, count2 = k-n%k, n//k  
        
        """В чем идея: n//k = количество элементов, которое может быть гарантированно 
           положено в кажду часть. Значит n%k, т.е. все что осталось, нельзя поделить 
           поровну между частями. Ну тогда раскидаем по единице в каждую часть начиная с начала, 
           это можно сделать, поскольку n%k < k. И раз требуется, чтобы части с большим количеством
           элементов шли первые, то определим переменные соответствующим образом:
           count1 = n//k+1, count2 = n//k. При этом количество итераций для создания первых частей 
           iters1 = n%k, т.к. остаток равен количеству частей в которые мы прибавим по единичке. 
           А iters2 = k-n%k. Итого: n%k частей с n//k+1 элементов, и k-n%k частей с n//k элементов."""
        
        res = []
        temp = head
        
        def fill_part(count, pointer):
            res.append(ListNode(val=pointer.val))
            part = res[-1]
            for _ in range(count-1):
                part.next = ListNode(val=pointer.next.val)
                part = part.next
                pointer = pointer.next
            pointer = pointer.next
        
        """Хоть и выглядит как два вложенных fora, итераций не больше чем n"""
        for _ in range(iters1):
            fill_part(count1, temp)
        
        for _ in range(iters2):
            if temp:
                fill_part(count2, temp)
            else:
                res.append(None)
        
        return res    
    
    """Working for O(n) time and O(n) space"""