class Solution {
private:
    int rows, cols;
    
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index){
        if (index == word.length()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r + 1, c, index +1) ||
                     dfs(board, word, r - 1, c, index +1) ||
                     dfs(board, word, r, c + 1, index +1) ||
                     dfs(board, word, r, c - 1, index +1);
        board[r][c] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board,string word) {
        rows = board.size();
        cols = board[0].size();
        if (word.length() > rows * cols) return false;
        
        unordered_map<char, int> board_freq, word_freq;
        for (const auto& row : board) {
            for (char ch : row) board_freq[ch]++;
        }
        for (char ch : word) word_freq[ch]++;
        for (auto const& [ch, count] : word_freq) {
            if (board_freq[ch] < count) return false;
        }
        if (board_freq[word.back()] < board_freq[word.front()]) {
            reverse(word.begin(), word.end());
        }
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) return true;
                }
            }
        }
        return false;
    }
};