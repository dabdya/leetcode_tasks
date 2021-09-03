class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        """Поделим nums на два массива P и N, в P все числа положительные, в N все отрицательные.
        Нужно составить массивы P и N так, что sum(P) - sum(N) = target.
        Добавим и вычтем в левую и правые части sum(P) + sum(N), получится:
        2sum(P) = target + sum(nums) => sum(P) = (target + sum(nums)) /2 
        Таким образом, задача сводится к следующей: найти подмассив в nums, 
        сумма элементов которого будет равна sum(P). Определить, есть ли такой массив
        или нет просто, это задача про существование подмассива с указанной суммой.
        А здесь нужно найти количество таких подмассивов"""
        
        s = sum(nums)
        if (s + target) % 2 != 0 or s < target:
            """Следует из вывода формулы"""
            return 0
        
        target_sum = (s + target) // 2
        if target_sum < 0:
            return 0
        """Сумма элементов искомого подмассива"""
        
        """ДП с оптимизацией памяти. См. задачу 416"""
        dp = [0] * (target_sum + 1)
        dp[0] = 1
        
        for num in nums:
            for i in range(target_sum, -1, -1):
                if i - num >= 0:
                    dp[i] += dp[i-num]
                    
        return dp[target_sum]