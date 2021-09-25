class Solution:
    def getMaximumXor(self, nums, maximumBit: int):
        n = len(nums)
        
        prefix_xors = [0]*n
        """prefix_xors[i] = nums[0]^nums[1]^...^nums[i]"""
        
        prefix_xors[0] = nums[0]
        for i in range(1,n):
            prefix_xors[i] = prefix_xors[i-1]^nums[i]
            
        """Важно заметить, что максимальное значение для каждого запроса которое нужно найти
           всегда будет k = 2^maxbit - 1, поскольку каким бы не был s = prefix_xor[i] на шаге i,
           всегда найдется такой t, что: s^t=k. Действительно, поскольку любое число можно
           представить в виде двоичной записи, то сделаем это для известных s и k. Затем
           пройдясь по каждому биту s на каждом шаге можно легко подобрать такой бит z_j, что
           s[j]^z_j=k[j] (на уровне двоичной таблицы истинности для xor это очевидно). 
           Тогда последовательность битов z_j будет образовывать число t в двоичном виде, 
           переведя его в десятичный вид получим ответ на запрос.
           
           Время работы для одного запроса: O(maxbit), память: O(1)
           
           Тогда для n запросов с учетом подсчета префиксных ксоров получим:
           время: O(n*maxbit), память: O(n)."""
        
        def find_var(s, k):
            """return t, where s^t=k"""
            s= bin(s)[2:] # убираем префикс 0b
            k = bin(k)[2:]
            
            n = max(len(s), len(k))
            s = s.rjust(n, '0')
            k = k.rjust(n, '0')
            
            res = 0
            for j in range(n):
                cond1 = s[j] == '0' and k[j] == '1'
                cond2 = s[j] == '1' and k[j] == '0'
                if cond1 or cond2:
                    res += 2**(n-j-1)
            
            return res
            
          
        res = [0]*n
        max_ = 2**maximumBit-1
        
        for i in range(n):
            res[i] = find_var(prefix_xors[n-i-1], max_)
        
        return res