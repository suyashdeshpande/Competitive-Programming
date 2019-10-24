class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0)
                    dp[i][j] = j == 0 ? grid[i][j] : grid[i][j] + dp[i][j - 1];
                else if(j == 0)
                    dp[i][j] = i == 0 ? grid[i][j] : grid[i][j] + dp[i -1 ][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
