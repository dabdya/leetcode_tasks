class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int num_islands = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                pair<int, int> u = { i, j };
                if (grid[i][j] == '1') {
                    DepthSearch(u, grid);
                    num_islands++;
                }
            }
        }
        
        return num_islands;
    }

private:
    void DepthSearch(pair<int, int>& v, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        grid[v.first][v.second] = '2';
        
        pair<int, int> up = { v.first - 1, v.second };
        if (v.first > 0 && grid[up.first][up.second] == '1') {
            DepthSearch(up, grid);
        }
        
        pair<int, int> down = { v.first + 1, v.second };
        if (v.first < n - 1 && grid[down.first][down.second] == '1') {
            DepthSearch(down, grid);
        }
        
        pair<int, int> left = { v.first, v.second - 1 };
        if (v.second > 0 && grid[left.first][left.second] == '1') {
            DepthSearch(left, grid);
        }
        
        pair<int, int> right = { v.first, v.second + 1 };
        if (v.second < m - 1 && grid[right.first][right.second] == '1') {
            DepthSearch(right, grid);
        }
    }
};