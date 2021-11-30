class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(2);
        
        vector<int> base(grid[0].size());
        for (int i = 0; i < grid[0].size(); i++) {
            if (i == 0) base[i] = grid[0][i];
            else base[i] = base[i - 1] + grid[0][i];
        }
        
        dp[0] = base;
        dp[1].assign(base.size(), 0);
        
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                
                if (j == 0) {
                    dp[i%2][j] = dp[(i - 1) % 2][j] + grid[i][j];
                }
                else {
                    dp[i%2][j] = min(dp[(i - 1) % 2][j], dp[i%2][j - 1]);
                    dp[i%2][j] += grid[i][j];
                }
                
            }
        }
        
        int k = (grid.size() % 2 == 0) ? 1 : 0;
        return dp[k][grid[0].size() - 1];
        
    }
};