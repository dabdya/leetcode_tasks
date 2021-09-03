class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_ = sum(nums)
        if sum_ % 2 != 0:
            """В таком случае на две части с одинаковой суммой разделить нельзя,
            поскольку если бы в обеих частях были четные суммы, или нечетные,
            то при сложении частичных сумм, общая сумма обязана была бы делиться пополам.
            Тогда остается случай, когда в одной части нечетная сумма, а в другой четная,
            а это и означает что суммарно получится нечетное число, т.к. если сложить
            нечетное число с четным, то результат всегда будет нечетным."""
            return False
        
        """Нужно найти подмножество, сумма элементов в котором будет равна половине исходной суммы.
        Тогда оставшаяся часть со второй половиной суммы будет принадлежать дополнению подмножества."""
        sum_ //= 2
        n = len(nums)
        
#         dp = [[0]*(sum_+1) for _ in range(n+1)]
#         """Размерность на один больше в обоих случаях под базу. Она ниже."""
        
#         dp[0][0] = True 
#         """dp[i][j] = true означает, что число j может быть получено арифметическим выражением 
#         из первых i элементов. При этом, некоторые из них могут быть не включены в выражение."""
        
#         for i in range(1, sum_+1):
#             dp[0][i] = False
#         """Следует исходя из правила, описанного выше"""
        
#         for i in range(1, n+1):
#             dp[i][0] = True
#         """Можно получить сумму ноль не включив ни один из элементов, если они ненулевые.
#         Если среди элементов есть нулевые, то тем более."""
        
#         for i in range(1, n+1):
#             for j in range(1, sum_+1):
#                 dp[i][j] = dp[i-1][j]
#                 if j - nums[i-1] >= 0:
#                     dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]]
#                 """В булевой решетке max это дизъюнкия, а min это конъюнкция."""
                
#         """Функция перехода. Можно либо включить i-ый элемент, либо нет. Тогда берется максимум
#         из этих двух вариантов, т.е. вариант с наибольним 'весом'. Если мы не берем i-ый элемент, то
#         d[i][j] = d[i-1][j], т.е. как бы делегируется достижение суммы j без i-ого элемента.
#         Если i-ый элемент был выбран, то d[i][j] = d[i-1][j-nums[i-1]], т.е. смотрим, достигается
#         ли сумма j-nums[i-1] за предыдущие i-1 элементов, и если да, то включившийся i-ый элемент
#         добьет j-nums[i-1] до j"""
        
#         return dp[n][sum_]

        """Оптимизация памяти до одномерного массива. Поскольку при вычислении элементов в новом массиве,
        нужен был только предыдущий, и каждый элемент был либо выше, либо левее, то можно поддерживать
        всегда однмерный массив размера sum_, заполняя его справа налево."""
    
        dp = [False] * (sum_+1)
        dp[0] = True
        
        for num in nums:
            for j in range(sum_, -1, -1): # идем справа налево
                if j - num >= 0:
                    dp[j] = dp[j] or dp[j - num]
                    
        return dp[sum_]