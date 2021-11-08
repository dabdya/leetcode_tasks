class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col;
        col.assign(n, false);
        
        vector<bool> diag1;
        vector<bool> diag2;
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);
        
        vector<vector<char>> rows(n);
        for (int i = 0; i < n; i++) {
            vector<char> row;
            row.assign(n, '.');
            rows[i] = row;
        }
    
        search(0, rows, col, diag1, diag2);
        
        return solutions;
    }
    
private:   
    vector<vector<string>> solutions;
    
    void search(int y, vector<vector<char>>& rows, vector<bool>& col, 
                vector<bool>& diag1, vector<bool>& diag2) {
        
        int n = col.size();
        
        if (y == n) {
            vector<string> solution;
            for (auto& row : rows) {
                string row_str(begin(row), end(row));
                solution.push_back(row_str);
            }
            solutions.push_back(solution);
            return;
        }
        
        for (int x = 0; x < n; x++) {
            
            if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) {
                continue;
            }
            
            col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
            rows[y][x] = 'Q';
            
            search(y + 1, rows, col, diag1, diag2);
            
            col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
            rows[y][x] = '.';
        }
        
    }
};