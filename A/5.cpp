class Solution {
public:
    string longestPalindrome(string s) {
        // return BruteForceApproach(s);
        // return DynamicProgrammingApproach(s);
        return ExpandAroundCenterApproach(s);
        
        /*
            В отличие от подхода с динамическим программированием,
            метод через расширение намного эффективнее, 
            хотя ассимптотика у них одинаковая.
            
            dynamic 1112ms < expand 16ms
        */
    }
    
private:
    
    string ExpandAroundCenterApproach(const string& s) {
        // time: O(n^2), space: O(1)
        
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int even = ExpandAroundCenter(i, i, s);
            int odd = ExpandAroundCenter(i, i + 1, s);
            int max_size = max(even, odd);
            
            if (max_size > end - start + 1) {
                start = i - (max_size - 1) / 2;
                end = i + max_size / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int ExpandAroundCenter(int i, int j, const string& s) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        
        return j - i - 1;
    }
    
    string DynamicProgrammingApproach(const string& s) {
        // time: O(n^2), space: O(n^2)
        
        vector<vector<bool>> dp;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            vector<bool> line;
            line.assign(n, false);
            line[i] = true;
            dp.push_back(line);
        }
        
        int start = 0;
        int end = 0;
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                
                dp[i][j] = s[i] == s[j];
                if (j - i > 2) {
                    dp[i][j] = dp[i][j] && dp[i + 1][j - 1];
                }
                
                if (dp[i][j] && j - i > end - start) {
                    start = i;
                    end = j;
                }
                
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    bool IsPalindrome(int i, int j, const string& s) {
        
        while(j - i >= 1) {
            if (s[j] != s[i]) return false;
            j--;
            i++;
        }
        
        return true;
    }
    
    string BruteForceApproach(const string& s) {
        // time: O(n^3), space: O(1)
        
        string lcp = s.substr(0, 1);
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (IsPalindrome(i, j, s)) {
                    if (j - i + 1 > lcp.size()) {
                        lcp = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        return lcp;
        
        // Time limit, because 10**9 is too many
    }
};