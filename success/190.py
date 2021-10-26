class Solution:
    def reverseBits(self, n: int) -> int:
        
        bits = bin(n)[2:].rjust(32, '0')
        
        res = 0
        for i in range(32):
            if bits[i] != '0':
                res += 2**i
        
        return res
    
    """time: O(logn) + O(n * logn) = O(n*logn)"""
            