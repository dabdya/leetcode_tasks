class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        
        greater = [0]*n
        less = [0]*n
        """Идея: заполнить два массива greater и less размера ratings, в которых 
        по индексу хранится количество элементов, которые больше/меньше чем ratings[i]"""
        
        for i in range(n):
            for j in range(i+1, n):
                if rating[i] > rating[j]:
                    greater[i] += 1
                else:
                    less[i] += 1
        
        """Теперь, поскольку нужно найти такие тройки индексов i<j<k, что
        rating[i]<ratings[j]<ratings[k] и rating[i]>ratings[j]>ratings[k],
        можно сделать двойной цикл, пробегаясь по парам, и если первый элемент
        пары меньше второго - смотреть в less[второго] сколько больше него.
        Аналогично в случае, если первый элемент больше второго."""
        
        result = 0
        for i in range(n):
            for j in range(i+1, n):
                if rating[i] > rating[j]:
                    result += greater[j]
                else:
                    result += less[j]
        
        return result
    
        """Есть вариант за O(n*logn) в discuss."""