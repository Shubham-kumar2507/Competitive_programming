class Solution {
public:

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // The path must start with an opening bracket
        // and end with a closing bracket.
        if (grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')') {
            return false;
        }

        // A valid parentheses string must have even length.
        int pathLength = m + n - 1;

        if (pathLength % 2 != 0) {
            return false;
        }

        // dp[i][j][brac]:
        // Whether a valid path is possible starting
        // from (i, j) with current bracket balance brac.
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return rec(grid, 0, 0, 0, dp);
    }

    bool rec(
        vector<vector<char>>& grid,
        int i,
        int j,
        int brac,
        vector<vector<vector<int>>>& dp
    ) {

        int m = grid.size();
        int n = grid[0].size();

        // Outside the grid
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        // Update bracket balance based on current cell
        if (grid[i][j] == '(') {
            brac++;
        }
        else {

            // A closing bracket without an
            // available opening bracket is invalid.
            if (brac > 0) {
                brac--;
            }
            else {
                return false;
            }
        }

        // Number of cells remaining after the current cell
        int remaining = (m - i) + (n - j) - 1;

        // If there are more open brackets than remaining cells,
        // there aren't enough positions left to close them.
        if (brac > remaining) {
            return false;
        }

        // Destination reached
        if (i == m - 1 && j == n - 1) {

            // A valid parentheses path must end with balance 0.
            return brac == 0;
        }

        // Already calculated this state
        if (dp[i][j][brac] != -1) {
            return dp[i][j][brac];
        }

        // Try moving down
        bool down = rec(
            grid,
            i + 1,
            j,
            brac,
            dp
        );

        // Try moving right
        bool right = rec(
            grid,
            i,
            j + 1,
            brac,
            dp
        );

        // If either path can form a valid sequence,
        // this state is valid.
        dp[i][j][brac] = down || right;

        return dp[i][j][brac];
    }
};