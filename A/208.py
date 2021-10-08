class Node:
    def __init__(self, letter):
        self.letter = letter
        self.childs = [None]*26
        self.is_word = False
        

class Trie:

    def __init__(self):
        # less than any english letter
        self.root = Node("$")
        

    def insert(self, word: str) -> None:
        
        n = len(word)
        cur = self.root
        for i in range(n):
            index = ord(word[i]) - ord("a")
            
            if not cur.childs[index]:
                cur.childs[index] = Node(word[i])
            
            cur = cur.childs[index]
        
        cur.is_word = True
        

    def search(self, word: str) -> bool:
        
        n = len(word)
        cur = self.root
        for i in range(n):
            
            index = ord(word[i]) - ord("a")
            if not cur.childs[index]:
                return False
            cur = cur.childs[index]
        
        return cur.is_word
        

    def startsWith(self, prefix: str) -> bool:
        
        n = len(prefix)
        cur = self.root
        for i in range(n):
            
            index = ord(prefix[i]) - ord("a")
            if not cur.childs[index]:
                return False
            cur = cur.childs[index]
        
        return True
    
    """Working for O(nm) time and O(n) space, m = len(word)"""