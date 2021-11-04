#include <queue>
#include <tuple>

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid[0][0] != 0) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<tuple<int, int, int>> q;
        q.push({ 0, 0, 1 });
        
        while (q.size() != 0) {
            
            tuple<int, int, int> v = q.front();
            q.pop();
            
            int x = get<0>(v);
            int y = get<1>(v);
            int h = get<2>(v);
            
            if (x == n - 1 && y == m - 1) return h;
            
            grid[x][y] = 2;
            
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    
                    if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m 
                        && grid[x + i][y + j] == 0) {
                        grid[x + i][y + j] = 2;
                        q.push({ x + i, y + j, h + 1});
                    }
                }
            }
            
        }
        
        return -1;
    }
};