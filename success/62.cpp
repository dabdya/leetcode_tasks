class Solution {
public:
    int uniquePaths(int m, int n) {   
        
        /*
            Проблема также решается с помощью 
            двумерного динамического программирования
        */
        
        vector<int> dp;
        dp.assign(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n - 1];
    }
};


class SolutionWithMemoization {
    public:
    int uniquePaths(int m, int n) {   
        return search(0, 0, m, n, 0);
    }
    
private:
    map<pair<int, int>, int> cache;
    
    int search(int i, int j, const int& m, const int& n, int paths) {
        
        if (cache.count({i, j}) == 1) {
            return cache[{i, j}];
        }
        
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        int result = 0;
        
        if (i + 1 < m) {
            int res = search(i + 1, j, m, n, 0);
            cache[{i + 1, j}] = res;
            result += res;
        }
        
        if (j + 1 < n) {
            int res = search(i, j + 1, m, n, 0);
            cache[{i, j + 1}] = res;
            result += res;
        }
        
        return result;
        
    }
};
