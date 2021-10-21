# from random import choice

# class RandomizedSet:

#     def __init__(self):
#         self._set = set()

#     def insert(self, val: int) -> bool:
#         if val in self._set:
#             return False
#         self._set.add(val)
#         return True

#     def remove(self, val: int) -> bool:
#         if val not in self._set:
#             return False
#         self._set.remove(val)
#         return True

#     def getRandom(self) -> int:
#         """Это операция не за константу, поскольку преобразвание в list линейно"""
#         return choice(list(self._set))


"""Выше решение которое сразу же пришло в голову, но оно не соответсвутет ограничением на время,
   хоть и проходит все тесты за разумное время."""

from random import randint as rnd

class RandomizedSet:

    def __init__(self):
        self.val_pos = dict()
        self.vals = list()

    def insert(self, val: int) -> bool:
        if val in self.val_pos:
            return False
        self.vals.append(val)
        self.val_pos[val] = len(self.vals)-1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.val_pos:
            return False
        rem_pos = self.val_pos[val]
        last_val = self.vals[-1]
        self.vals[rem_pos], self.vals[-1] = last_val, val
        
        """Поменяли местами элемент который нужно 
           удалить и последний элемент"""
        
        self.val_pos[last_val] = rem_pos
        del self.val_pos[val]
        self.vals.pop()
        return True

    def getRandom(self) -> int:
        return self.vals[rnd(0, len(self.vals)-1)]
    
    
"""Почему это решение работает за время в среднем O(1)?
   Потому что вставка/удаление в лист (динамическиц массив) идет амаротизированно за O(1), 
   а вставка и удаление из словаря идет за константу, при условии что выбрана хорошая хэш-функция,
   но я думаю не стоит сомневаться в структурах из стандартных библиотек
   
   Амортизированно O(f) - это значит что если есть последовательность из n операций 
   на структуре данных, то время выполнения всех n операция будет O(fn)"""

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()