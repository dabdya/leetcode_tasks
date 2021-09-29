from heapq import heappush, heappop

class Solution:
    def sortArrayByParityII(self, nums):
        odd = []
        even = []
        
#         for num in nums:
#             if num % 2 == 0:
#                 heappush(even, num)
#             else:
#                 heappush(odd, num)
            
        
#         n = len(nums)
#         for i in range(n):
#             if i % 2 == 0:
#                 nums[i] = heappop(even)
#             else:
#                 nums[i] = heappop(odd)
        
        for num in nums:
            if num % 2 == 0:
                even.append(num)
            else:
                odd.append(num)
        
        even.sort()
        odd.sort()
        
        n = len(nums)
        for i in range(n):
            if i % 2 == 0:
                nums[i] = even[i//2]
            else:
                nums[i] = odd[i//2]
                
        """Это второй способ, я предположил, что он работает быстрее, поскольку процессоры
           дружелюбнее к массивам, к чтению кэш линий."""
            
        return nums
        """Working for O(nlogn) time and O(n) space"""
        """Тут должны гарантироваться тепличные условия, поскольку если четных больше чем нечетных, 
           то четное обязательное окажется на нечетной позиции, это будет противоречить условиям задачи."""