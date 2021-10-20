from queue import Queue

class Solution:
    def floodFill(self, image, sr: int, sc: int, newColor: int):
        
        n = len(image)
        m = len(image[0])
        
        queue = Queue()
        queue.put((sr,sc))
        
        visited = set()
        """В подходе с visited потребление памяти осталось таким же, но
           сократилось число итераций, из-за чего улучшилась временная ассимптотика"""
        
        while queue.qsize() != 0:
            i,j = queue.get()
#             if image[i][j] == newColor:
#                 continue

            visited.add((i,j))
            
            if i-1 >= 0 and image[i-1][j] == image[i][j] and (i-1,j) not in visited:
                queue.put((i-1,j))
                
            if i+1 < n and image[i+1][j] == image[i][j] and (i+1,j) not in visited:
                queue.put((i+1,j))
            
            if j-1 >= 0 and image[i][j-1] == image[i][j] and (i,j-1) not in visited:
                queue.put((i,j-1))
            
            if j+1 < m and image[i][j+1] == image[i][j] and (i,j+1) not in visited:
                queue.put((i,j+1))
                
            image[i][j] = newColor
        
        return image