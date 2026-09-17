class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink the window if sum exceeds target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // If we find a subarray with target sum
            if (sum == target) {

                int len = right - left + 1;

                // Check if another subarray exists before this
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store minimum length till current index
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }

            } else {

                // Carry forward the previous minimum
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};