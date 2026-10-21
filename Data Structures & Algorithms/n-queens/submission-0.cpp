class Solution {
public:
    bool isSafe(int n, vector<string> &board, int row, int col)
    {
        if (row < 0 || col < 0 || row >= n || col >= n)
        {
            return false;
        }

        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(int n, vector<string> &board, vector<vector<string>> &res, int row)
    {
        if (row >= n)
        {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(n, board, row, i))
            {
                board[row][i] = 'Q';
                backtrack(n, board, res, row + 1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board;

        string row = "";
        for (int i = 0; i < n; i++)
        {
            row += '.';
        }
        for (int i = 0; i < n; i++)
        {
            board.push_back(row);
        }

        backtrack(n, board, res, 0);

        return res;
    }
};
