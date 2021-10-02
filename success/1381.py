class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = [0]*maxSize
        self.head = -1

    def push(self, x: int):
        if self.head+1 == len(self.stack):
            return
        
        self.head += 1
        self.stack[self.head] = x

    def pop(self):
        if self.head == -1:
            return -1
        
        self.head -= 1
        return self.stack[self.head+1]

    def increment(self, k: int, val: int):
        for i in range(min(k,len(self.stack))):
            self.stack[i] += val
