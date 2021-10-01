class SegmentTree:
    def __init__(self, arr, op):
        self.op = op
        self.__arr = arr
        self.__tree = [0]*(4*len(arr))
    
    def build(self, v, tl, tr):
        if tl == tr:
            self.__tree[v] = self.__arr[tl]
            return
        
        mid = (tl + tr) // 2
        self.build(v*2, tl, mid)
        self.build(v*2+1, mid+1, tr)
        self.__tree[v] = self.op(self.__tree[v*2], self.__tree[v*2+1])
            
    def get(self, v, tl, tr, l, r):
        if l > r: return 0
        if tl == l and tr == r:
            return self.__tree[v]
        
        mid = (tl + tr) // 2
        left_part = self.get(v*2, tl, mid, l, min(r,mid))
        right_part = self.get(v*2+1, mid+1, tr, max(l, mid+1), r)
        return self.op(left_part, right_part)

    
class Solution:
    def xorQueries(self, arr, queries):
#         # https://e-maxx.ru/algo/segment_tree
#         n = len(arr)
#         tree = SegmentTree(arr, lambda x,y: x^y)
#         tree.build(1, 0, n-1)
        
#         return [tree.get(1, 0, n-1, l, r) for l,r in queries]

        """Можно не строить дерево отрезков, а просто использовать префиксную сумму,
           оно конечно же лучше по памяти и за счет кэш линий быстрее, чем дерево"""
        
        n = len(arr)
        prefixes = [0]*(n)
        prefixes[0] = arr[0]
        for i in range(1,n):
            prefixes[i] = prefixes[i-1]^arr[i]
        
        return [prefixes[r] if l == 0 else prefixes[r]^prefixes[l-1] for l,r in queries]