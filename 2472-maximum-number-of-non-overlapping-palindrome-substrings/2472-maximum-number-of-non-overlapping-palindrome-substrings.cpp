class Solution {
public:
    int maxPalindromes(string s, int k) {

         int n = s.size();

        // palindrome[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (len == 1) {
                    palindrome[i][j] = true;
                }
                else if (len == 2) {
                    palindrome[i][j] = (s[i] == s[j]);
                }
                else {
                    palindrome[i][j] =
                        (s[i] == s[j]) && palindrome[i + 1][j - 1];
                }
            }
        }

        // dp[i] = maximum palindromes using s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't use character i-1
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int j = 0; j <= i - k; j++) {

                if (palindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
        
    }
};