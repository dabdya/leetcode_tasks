from heapq import heappush, heappop

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        
        """Реализация моей идеи, которая вылетает c TL.
           Время работы O(n*log[n*k])
           Пространственная сложность: O(n)"""
#         heap  = [1]
#         cache = {1}
        
#         while n:
#             nxt = heappop(heap)
#             for prime in primes:
#                 a = prime*nxt
#                 if a not in cache:
#                     heappush(heap, a)
#                     cache.add(a)
            
#             n -= 1
        
#         return nxt

        """Оказывается, можно сделать за O(n*logk)
           Идея основана на том, что каждое уродливое число получается из предыдущего, 
           умноженного на простое число. Число 1 уродиливое как база функции. Таким образом, 
           все элементы primes уже уродливые, осталось найти остальные и решить задачу.
           """
    
        dp = [0]*n
        dp[0] = 1
        
        heap = []
        for prime in primes:
            """число = prime * prime, само prime, индекс числа в dp, 
               на которое было последнее умножение"""
            
            item = prime*1, prime, 0
            heappush(heap, item)
            
        count = 1 # сколько чисел было добавлено в dp, нужно поддерживать из-за дублей
        while count < n:
            item = heappop(heap)
            num, prime, index = item
            
            if num != dp[count-1]:
                dp[count] = num
                count += 1
            
            """index+1 следующее число в массиве dp на которое нужно умножить prime"""
            heappush(heap, (prime*dp[index+1], prime, index+1))
            
        return dp[n-1]