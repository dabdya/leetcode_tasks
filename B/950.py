class Solution:
    def deckRevealedIncreasing(self, deck):
        deck.sort()
        n = len(deck)
        
        if n == 1:
            return deck
        
        """Если идти по отсортированному списку с шагом один, то получатся все
           карты, которые будут развернуты первые, таким образом они должны сохранить
           свой порядок по возрастанию и пойти в ответ на позициях через один."""
        
        result = [0]*n
        
        iters = n//2 + 1 if n % 2 != 0 else n//2
        for i in range(iters):
            result[i*2] = deck[i]
            
        """Рекурсивно вызываем решение для оставшихся чисел"""
        rest = self.deckRevealedIncreasing(deck[iters:])
        
        """Если четности не совпадают частей не совпадают, 
           то надо последний элемент протащить в начало, 
           чтобы один лишний сдвиг сразу же убрал его в конец"""
        
        if iters != n - iters:
            for i in range(len(rest)-1,0,-1):
                rest[i], rest[i-1] = rest[i-1], rest[i]
        
        """Заполняем пропуски"""
        count = 0
        for i in range(n):
            if not result[i]:
                result[i] = rest[count]
                count += 1
            
        return result
        