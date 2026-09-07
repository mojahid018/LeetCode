class Solution {
public:
    int distinctSubseqII(string s) {

          const int MOD = 1e9 + 7;

        int n = s.size();

        // dp[i] = number of distinct subsequences
        // using first i characters, including empty subsequence
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        // Last position of each character
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {

            // Every existing subsequence:
            // either take s[i-1] or don't take it
            dp[i] = (2 * dp[i - 1]) % MOD;

            int ch = s[i - 1] - 'a';

            // Remove duplicate subsequences
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;
            }

            last[ch] = i;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
        
    }
};