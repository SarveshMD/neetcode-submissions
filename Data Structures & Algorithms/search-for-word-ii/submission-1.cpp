class TrieNode {
public:
    bool endOfWord = false;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    TrieNode* constructTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word: words) {
            TrieNode* curr = root;
            for (char c: word) {
                if (!curr->children[c]) curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
            curr->endOfWord = true;
        }
        return root;
    }
    vector<string> res;
    void dfs(vector<vector<char>>& board, int i, int j, 
    TrieNode* subTrie, vector<vector<int>>& visited,
    string& path) {
        if (i < 0 || j < 0 
            || i >= board.size() || j >= board[0].size()
            || visited[i][j]
            || !subTrie->children[board[i][j]]) return;
        TrieNode* nextChild = subTrie->children[board[i][j]];
        path.push_back(board[i][j]);
        if (nextChild->endOfWord) {
            res.push_back(path);
            nextChild->endOfWord = false;
        }
        visited[i][j] = 1;
        dfs(board, i+1, j, nextChild, visited, path);
        dfs(board, i-1, j, nextChild, visited, path);
        dfs(board, i, j+1, nextChild, visited, path);
        dfs(board, i, j-1, nextChild, visited, path);
        visited[i][j] = 0;
        path.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        TrieNode* root = constructTrie(words);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        string path = "";
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                dfs(board, i, j, root, visited, path);
            }
        }
        return res;
    }
};
