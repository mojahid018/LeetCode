class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

         vector<int> diff;
        long long k = 1LL * k1 + k2;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            mx = max(mx, d);
        }

        // Enough operations to make all differences zero
        if (total <= k)
            return 0;

        int low = 0, high = mx;

        // Find the minimum achievable maximum difference
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                if (d > mid)
                    ops += d - mid;
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;

        // Reduce every difference to at most 'level'
        for (int& d : diff) {
            if (d > level) {
                k -= d - level;
                d = level;
            }
        }

        // Use leftover operations to reduce equal maximums
        for (int& d : diff) {
            if (k == 0)
                break;

            if (d == level) {
                d--;
                k--;
            }
        }

        // Calculate sum of squares
        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
        
    }
};