class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            unordered_set<char> curr_row;
            for (int j=0; j<9; j++) {
                char c = board[i][j];
                if (c != '.' && curr_row.contains(c)) return false;
                if (c != '.') curr_row.insert(c);
            }
        }
        for (int i=0; i<9; i++) {
            unordered_set<char> curr_col;
            for (int j=0; j<9; j++) {
                char c = board[j][i];
                if (c != '.' && curr_col.contains(c)) return false;
                if (c != '.') curr_col.insert(c);
            }
        }
        vector<vector<unordered_set<char>>> sub_box_grid(3, vector<unordered_set<char>>(3));
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                int r = i/3;
                int c = j/3;
                char num = board[i][j];
                if (num != '.' && sub_box_grid[r][c].contains(num)) return false;
                if (num != '.') sub_box_grid[r][c].insert(num);
            }
        }
        return true;
    }
};
