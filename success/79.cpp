class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DepthSearch(i, j, board, 0, word)) {
                        return true;
                }
            }
        } 
        
        return false;
    }

private:
    
    bool DepthSearch(int i, int j, vector<vector<char>>& board, int ptr, const string& word) {
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || word[ptr] != board[i][j]) { return false; }
        
        ptr++;
        if (ptr == word.size()) return true;
        
        char old_letter = board[i][j];
        board[i][j] = '$';
        
        bool found = 
            DepthSearch(i - 1, j, board, ptr, word) ||
            DepthSearch(i + 1, j, board, ptr, word) ||
            DepthSearch(i, j - 1, board, ptr, word) ||
            DepthSearch(i, j + 1, board, ptr, word);
        
        board[i][j] = old_letter;
        return found;
        
    }
};