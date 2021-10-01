class Solution:
    def canPartitionKSubsets(self, nums, k):
        n = len(nums)
        s = sum(nums)
        
        """Проверка необходимого условия для решения задачи"""
        if s % k != 0:
            return False
        s //= k
        
        def dfs(start_index, cur_sum):
            if cur_sum == s:
                return True
            
            for i in range(start_index, n):
                if not visited[i] and cur_sum + nums[i] <= s:
                    visited[i] = 1
                    if dfs(i+1, cur_sum + nums[i]):
                        return True
                    """Снимаем посещенность, если элемент i не попал в контейнер, возможно,
                       пригодится в другом контейнере."""
                    visited[i] = 0
            return False
        
        nums.sort(reverse=True)
        """Сортировка важна, контрпример [1,1,1,1,2,2,2,2], k=4, т.е. сбор контейнеров надо начинать
           с бОльших чисел, и добивать уже в конце мелкими."""
        
        visited = [0]*n
        for _ in range(k):
            """Идея: нужно собрать k контейнеров с суммой s. Собираем первый, помечаем все входящие
               в него элементы через visited. Идем к следующему и пытаемся собрать, не используя элементы,
               которые уже находятся в другом контейнере. Если не получилось, сразу же прерываемся, 
               иначе продолжаем заполнять
               ."""
            if not dfs(0,0):
                return False
        return True
    
    """Working for O(k*2^n) time and O(n) space"""