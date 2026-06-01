class Solution {
public:
    bool exists = false;
    void backtrack(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<int>>& visited) {
        int length = word.size();
        if (index == length) {
            exists = true;
            return;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]) return;
        // cout << format("Visiting i:{}, j:{}, board[i][j]:{}\n", i, j, board[i][j]);
        visited[i][j] = 1;
        if (board[i][j] == word[index]) {
            index++;
            backtrack(board, word, i+1, j, index, visited);
            backtrack(board, word, i-1, j, index, visited);
            backtrack(board, word, i, j+1, index, visited);
            backtrack(board, word, i, j-1, index, visited);
        }
        visited[i][j] = 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m && !exists; i++) {
            for (int j=0; j<n && !exists; j++) {
                vector<vector<int>> visited(m, vector<int>(n, 0));
                backtrack(board, word, i, j, 0, visited);
            }
        }
        return exists;
    }
};
