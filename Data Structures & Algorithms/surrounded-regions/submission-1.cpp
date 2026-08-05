class Solution {
public:
    int rows;
    int cols;
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1 , 0},
        {0, -1},
        {0, 1}
    };

    void dfs(vector<vector<char>>& board, int r, int c) {
        for (auto [dr, dc]: directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;

            if (board[nr][nc] == 'O') {
                board[nr][nc] = '#';
                dfs(board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (board[i][j] == 'O' && 
                (i == 0 || i == rows-1 || j == 0 || j == cols-1)) {
                    board[i][j] = '#';
                    dfs(board, i, j);
                }
            }
        }

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
