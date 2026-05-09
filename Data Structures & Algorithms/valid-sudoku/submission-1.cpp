class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        vector<unordered_set<int>> row_hash(9);
        vector<unordered_set<int>> col_hash(9);
        vector<vector<unordered_set<int>>> square_hash(3, vector<unordered_set<int>>(3));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                if (row_hash[i].contains(board[i][j]) ||
                    col_hash[j].contains(board[i][j]) ||
                    square_hash[i/3][j/3].contains(board[i][j])
                ) return false;
                row_hash[i].insert(board[i][j]);
                col_hash[j].insert(board[i][j]);
                square_hash[i/3][j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};
