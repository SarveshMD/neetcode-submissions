class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        for (int i=0; i<n; i++) {
            unordered_set<int> hash;
            for (int j=0; j<n; j++) {
                if (hash.contains(board[i][j])) return false;
                if (board[i][j]!= '.')
                    hash.insert(board[i][j]);
            }
        }
        for (int j=0; j<n; j++) {
            unordered_set<int> hash;
            for (int i=0; i<n; i++) {
                if (hash.contains(board[i][j])) return false;
                if (board[i][j]!= '.')
                    hash.insert(board[i][j]);
            }
        }
        vector<vector<unordered_set<int>>> hashes(3, vector<unordered_set<int>>(3));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (hashes[i/3][j/3].contains(board[i][j])) return false;
                if (board[i][j]!= '.')
                    hashes[i/3][j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};
