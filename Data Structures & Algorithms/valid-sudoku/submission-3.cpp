class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_hash(9);
        vector<unordered_set<char>> col_hash(9);
        vector<vector<unordered_set<char>>> sub_box_grid(3, vector<unordered_set<char>>(3));
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char num = board[i][j];
                if (num == '.') continue;
                int r = i/3;
                int c = j/3;
                if (sub_box_grid[r][c].contains(num) || 
                    row_hash[i].contains(num) ||
                    col_hash[j].contains(num)) 
                    return false;
                sub_box_grid[r][c].insert(num);
                row_hash[i].insert(num);
                col_hash[j].insert(num);
            }
        }
        return true;
    }
};
