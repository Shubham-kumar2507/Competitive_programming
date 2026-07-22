class TrieNode {
public:
    TrieNode* children[26];
    string word; // Stores the full word at leaf nodes to make result collection easy
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
private:
    vector<string> result;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word; // Mark the end of the word
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr) {
        char ch = board[i][j];
        int idx = ch - 'a';

        // Base case: if child doesn't exist, terminate search
        if (!curr->children[idx]) return;

        curr = curr->children[idx];

        // If a valid word is found, add to result and reset to avoid duplicates
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }

        // Mark cell as visited
        board[i][j] = '$';

        // Explore all 4 directions
        for (const auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size() && board[new_i][new_j] != '$') {
                dfs(board, new_i, new_j, curr);
            }
        }

        // Backtrack
        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // 1. Build the Trie
        for (const string& word : words) {
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();

        // 2. Perform DFS from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};