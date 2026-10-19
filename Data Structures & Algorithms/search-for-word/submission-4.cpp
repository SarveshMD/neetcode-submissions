class Solution {
public:
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1 , 0},
        {0 , -1},
        {0 , 1}
    };

    void backtrack(vector<vector<char>>& board, string word, int idx, vector<vector<bool>>& curr_path, bool& res, int row, int col) {
        if (res) return;
        if (row >= board.size() || col >= board[0].size()) return;
        if (idx >= word.size()) return;
        if (curr_path[row][col]) return;

        if (board[row][col] == word[idx]) {
            if (idx == word.size()-1) {
                res = true;
                return;
            }
            curr_path[row][col] = true;
            for (auto dir: directions) {
                int next_row = row + dir.first;
                int next_col = col + dir.second;
                backtrack(board, word, idx+1, curr_path, res, next_row, next_col);
            }
            curr_path[row][col] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                vector<vector<bool>> curr_path(board.size(), vector<bool>(board[0].size(), false));
                backtrack(board, word, 0, curr_path, res, i, j);
            }
        }

        return res;
    }
};
