class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = LongestCommonSubsequence(word1, word2);
        return word1.size() + word2.size() - 2 * lcs;
    }
    
private:
    int LongestCommonSubsequence(const string& t1, const string& t2) {
        int n = t1.size() + 1;
        int m = t2.size() + 1;
        
        vector<vector<int>> dp(2);
        for (int i = 0; i < 2; i++) {
            dp[i].assign(m, 0);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                
                dp[i%2][j] = max(dp[i%2][j - 1], dp[(i - 1)%2][j]);
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i%2][j] = dp[(i - 1)%2][j - 1] + 1;
                }
            }
        }
        
        int i = (n - 1) % 2 == 0? 0 : 1;
        return dp[i][m - 1];
    }
};