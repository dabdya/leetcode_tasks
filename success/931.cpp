class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        size_t n = matrix.size();
        
        vector<vector<int>> dp(2);
        for (int i = 0; i < 2; i++) {
            if (i == 0) dp[i] = matrix[i];
            else dp[i].assign(n, 0);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i%2][j] = dp[(i - 1)%2][j];
                
                if (j - 1 >= 0) {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i - 1)%2][j - 1]);
                }
                
                if (j + 1 < n) {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i - 1)%2][j + 1]);
                }
                
                dp[i%2][j] += matrix[i][j];
            }
        }
        
        int ind = (n % 2 == 0) ? 1 : 0;
        return *min_element(begin(dp[ind]), end(dp[ind]));
        
    }
};