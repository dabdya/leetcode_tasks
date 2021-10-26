class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
#         if n == 0: return False
#         binstr = bin(n)[2:]
#         """Перевод в бинарный вид за O(logn)"""
        
#         for i in range(1, len(binstr)):
#             if binstr[i] != '0':
#                 return False
        
#         """В цикле не больше 32 итераций согласно ограничениям из условия
#            Итого по времени O(logn)"""
        
#         return True
        
         """Поскольку ведущих нулей нет, то должна быть всего одна единица если число
            явялется степенью двойки и bound case n >= 0"""
         return bin(n).count("1") == 1 and n >=0