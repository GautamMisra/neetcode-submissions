class Solution {
public:
    void solve(int row, int n,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<bool>& colUsed,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        // All n queens have been placed
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in the current row
        for(int col = 0; col < n; col++) {

            // Check column and both diagonals
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if(colUsed[col] || diag1[d1] || diag2[d2])
                continue;

            // Place queen
            board[row][col] = 'Q';
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // Move to next row
            solve(row + 1, n, board, ans,
                  colUsed, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        vector<bool> colUsed(n, false);

        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, board, ans,
              colUsed, diag1, diag2);

        return ans;
    }
};
