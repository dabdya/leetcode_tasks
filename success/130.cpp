class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        /*
            Захватятся все островки у которых нет элементов около границы
            Каждая компонента связности - отдельный островок
            Запукаем от нулевых границ поиск в глубину, перекрашиваем клетки на пути в Z,
            тогда после поиска оставшиеся O должны превратиться в X
        */
        
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < board.size(); i++) {

            if (i == 0 || i == n - 1) {
                for (int j = 0; j < board[0].size(); j++) {
                    pair<int, int> v = { i, j };
                    if (board[i][j] == 'O') {
                        DepthSearch(v, board);
                    }
                }
            }
            else {
                pair<int, int> v = { i, 0 };
                if (board[i][0] == 'O') {
                    DepthSearch(v, board);
                }
                
                pair<int, int> u = { i, m - 1 };
                if (board[i][m - 1] == 'O') {
                    DepthSearch(u, board);
                }
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void DepthSearch(
        const pair<int, int>& v, vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        board[v.first][v.second] = 'Z';
        
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                
                pair<int, int> x = { v.first + i, v.second };
                if (j == 0 && x.first >=0 && x.first < n 
                    && board[x.first][x.second] == 'O') {
                    DepthSearch(x, board);
                }
                
                pair<int, int> y = { v.first, v.second + j };
                if (i == 0 && y.second >= 0 && y.second < m
                   && board[y.first][y.second] == 'O') {
                    DepthSearch(y, board);
                }
            }
        }
}
};