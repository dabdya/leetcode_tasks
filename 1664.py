class Solution:
    def waysToMakeFair(self, nums) -> int:
        n = len(nums)
        even_sum = [0]*n
        odd_sum = [0]*n
        
        even_sum[0] = nums[0]
        for i in range(1,n):
            even_sum[i] = even_sum[i-1]
            odd_sum[i] = odd_sum[i-1]
            
            if i % 2 == 0:
                even_sum[i] += nums[i]
            else:
                odd_sum[i] += nums[i]
                
        """Здесь dp[i] = сумма от 0 до i включительно четных и нечетных элементов.
           Более конкретно: even_sum[i] - четных, odd_sum[i] - нечетных."""
        
        res = 0
        for i in range(n):
            """Считаем нечетную и четную сумму справа от индекса i, это легко сделать
               поскольку есть значение на всем массиве, и значение на подмассиве 0:i."""
            odd_right = odd_sum[-1] - odd_sum[i]
            even_right = even_sum[-1] - even_sum[i]
        
            """При удалении i-ого элемента ориентация слева сохраняется, осталось только
               сохранить это в перменные и удалить из какой-то число по индексу i."""
            odd_left = odd_sum[i]
            even_left = even_sum[i]
            if i % 2 == 0:
                even_left -= nums[i]
            else:
                odd_left -= nums[i]
            
            """Справа ориентация инвертируется, поэтому осталось проверить на равенство"""
            if odd_left + even_right == even_left + odd_right:
                res += 1
        
        return res