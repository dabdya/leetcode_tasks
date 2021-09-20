from string import ascii_lowercase as alph


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(s)
        mod = len(alph)
        
        d = {letter: i for i,letter in enumerate(alph)}
        
        #res = [""]*n
        shift = 0
        for i in range(n-1,-1,-1):
            shift += shifts[i]
            #shifts[i] = alph[(alph.find(s[i]) + shift) % mod]
            shifts[i] = alph[(d[s[i]] + shift) % mod]
        return "".join(shifts)
        #return "".join(res)
    
        """Данный подход использует O(n) памяти и работает за время O(n * len(alph)).
           Можно оптимизировать по времени до O(n), но тогда в затраты на память придется
           дополнительно добавить O(len(alph)). Но это как бы не зависит от n, поэтому
           считается константой. С другой стороны для времени это тоже константа.
           По настоящему круто было избавиться от дополнительной памяти в виде res.
           И такой вариант есть, просто переиспользовать массив shifts (текущий вариант).
           Теперь можно оптимизировать и время, выделив константный словарь перед циклом,
           убирая поиск за O(len(alph)) на каждой итерации. 
           Полученное решенние по метрикам лучше и первого, и второго."""