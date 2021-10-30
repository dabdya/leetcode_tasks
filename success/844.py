class Solution:
    def get_stack_by_str(self, string):
        stack = []
        for char in string:
            if char == "#":
                if stack:
                    stack.pop()
            else:
                stack.append(char)
        return stack
    
    def backspaceCompare(self, s: str, t: str) -> bool:
        
        stack_s = self.get_stack_by_str(s)
        stack_t = self.get_stack_by_str(t)
        
        if len(stack_s) != len(stack_t):
            return False
        
        while stack_s and stack_t:
            char_s = stack_s.pop()
            char_t = stack_t.pop()
            if char_s != char_t:
                return False
        
        return True        