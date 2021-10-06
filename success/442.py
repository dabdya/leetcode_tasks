class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
#         set_nums = set()
        
#         result = []
#         for num in nums:
#             if num in set_nums:
#                 result.append(num)
#             else:
#                 set_nums.add(num)
        
#         return result

        """Первое что пришло в голову с дополнительной памятью написано выше"""
    
        """Подход основан на том, что если n=len(nums), то все элементы массива 1<=nums[i]<=n"""
        result = []
        for num in nums:
            if nums[abs(num)-1] < 0:
                result.append(abs(num))
            else:
                nums[abs(num)-1] *= -1
        
        return result