class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

         int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // First and last characters must be '(' and ')'
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;

        vector<vector<unordered_set<int>>> dp(m,
            vector<unordered_set<int>>(n));

        dp[0][0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= m + n; balance++) {

                    if (grid[i][j] == '(') {
                        int prevBalance = balance - 1;

                        if (prevBalance >= 0) {
                            if (i > 0 && dp[i - 1][j].count(prevBalance))
                                dp[i][j].insert(balance);

                            if (j > 0 && dp[i][j - 1].count(prevBalance))
                                dp[i][j].insert(balance);
                        }
                    }
                    else {
                        int prevBalance = balance + 1;

                        if (i > 0 && dp[i - 1][j].count(prevBalance))
                            dp[i][j].insert(balance);

                        if (j > 0 && dp[i][j - 1].count(prevBalance))
                            dp[i][j].insert(balance);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
        
    }
};