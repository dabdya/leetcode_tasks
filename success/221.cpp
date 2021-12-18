class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int result = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                    
                int n = i, m = j;
                while (n < matrix.size() && m < matrix[n].size() && matrix[n][m] == '1') {
                                        
                    bool ones_vertical = true;
                    for (int y = i; y < n; y++) {
                        if (matrix[y][m] != '1') {
                            ones_vertical = false;
                            break;
                        }
                    }
                    
                    if (!ones_vertical) break;
                    
                    bool ones_horizontal = true;
                    for (int x = j; x < m; x++) {
                        if (matrix[n][x] != '1') {
                            ones_horizontal = false;
                            break;
                        }
                    }
                    
                    if (ones_horizontal) {
                        result = max(result, (n-i+1)*(n-i+1));
                    }
                    else break;
                    
                    n++, m++;
                }
                
            }
        }
        
        return result;
    }
};