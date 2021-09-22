class Solution:
    def maxLength(self, arr: List[str]) -> int:
        self.res = 0
        self.dfs(arr, "", 0)
        return self.res
    
    """В чем идея: перебирать всевозможные комбинации.
       Начинаем с пустой строки и постепенно прибавляем строки, проверяя что
       результирующая строка содержит только уникальные символы и поддерживая
       максимум в таком случае в переменной класса.
       
       Временная сложность O(2^n), т.е. всевозможные сочетания == число подмножеств
       Пространственная сложность O(1)"""                                                      
    
    def dfs(self, arr, comb, ind):
        
        unique = len(comb) == len(set(comb))
        
        if unique:
            self.res = max(self.res, len(comb))
            
        if not unique or ind == len(arr):
            return
        
        for i in range(ind, len(arr)):
            self.dfs(arr, comb+arr[i], i+1)