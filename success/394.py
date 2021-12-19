class Solution:
    def decodeString(self, s: str) -> str:
        
        stack = []
        for letter in s:
            if letter == ']':
                
                subtext = []
                prev = stack.pop()
                while prev != '[':
                    subtext.append(prev)
                    prev = stack.pop()
                prev = stack.pop()
                
                digits = []
                while prev.isdigit():
                    digits.append(prev)
                    if len(stack):
                        prev = stack.pop()
                    else: break
                
                if not prev.isdigit():
                    stack.append(prev)
                
                subtext.reverse()
                digits.reverse()
                
                count = int("".join(digits))
                stack.append(count * str("".join(subtext)))
                
            else:
                stack.append(letter)
        
        return "".join(stack)