class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0]*n
        dp[0] = nums[0]
        """dp[i] = s, означает, что на отрезке [0,i] есть подмассив, с максимальной суммой s.
        Причем либо это полный подмассив [0,i], либо просто элемент i. Иначе нарушается
        определение подмассива, т.е. его непрерывность. Можно привести пример: [3, -1, 1].
        На отрезке [0,1] максимум 2, но если не учитывать непрерывность, то максимум 3, это
        элемент по первому индексу. Тогда при переходе на отрезок [0,2] максимум будет 4, но
        на таком отрезке не надйется подмассива с такой суммой."""
        
        """Либо включаем предыдущий элемент, и не прерываем подмассив,
        либо не включаем предыдущий элемент, и начинаем заново с текущего элемента.
        Из этих вариантов нужно взять максимальный, т.е. с большей суммой в подмассиве."""
        result = dp[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
            result = max(result, dp[i])
        
        """Ответ не обязательно в последней ячейке, поскольку элементы могут уменьшать сумму
        в накопленном подмассиве, и остается либо уменьшить, либо начать заново, поэтому
        в цикле поддерживалась переменная с максимальным значением на всех подмассивах."""
        return result