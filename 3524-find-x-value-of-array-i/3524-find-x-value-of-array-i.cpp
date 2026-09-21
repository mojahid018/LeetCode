class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

         vector<long long> result(k, 0);

        vector<long long> dp(k, 0);

        for (int num : nums) {

            vector<long long> newDp(k, 0);

            int rem = num % k;

            // Start a new subarray with the current element
            newDp[rem]++;

            // Extend previous subarrays
            for (int i = 0; i < k; i++) {

                int newRem = (i * rem) % k;

                newDp[newRem] += dp[i];
            }

            // Add the current subarray counts to the answer
            for (int i = 0; i < k; i++) {
                result[i] += newDp[i];
            }

            // Update DP
            dp = newDp;
        }

        return result;
        
        
    }
};