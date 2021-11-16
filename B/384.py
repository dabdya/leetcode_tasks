from random import randint as rnd

class Solution:

    def __init__(self, nums: List[int]):
        self._nums = nums
        self._aux = nums[:]

    def reset(self) -> List[int]:
        self._aux = self._nums[:]
        return self._nums

    def shuffle(self) -> List[int]:
        self.reset()
        n = len(self._aux)
        result = []
        
        for i in range(n):
            j = rnd(0, n - i - 1)
            result.append(self._aux[j])
            self._aux[j], self._aux[-i-1] = self._aux[-i-1], self._aux[j]
        
        return result


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()