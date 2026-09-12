class Solution {
public:

    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(Node &a, Node &b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(arr.begin(), arr.end());

        // Find next non-overlapping interval
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (arr[mid][0] > arr[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        // dp[i][k]
        // maximum result from i onwards
        // selecting at most k intervals
        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Don't take current interval
                Node skip = dp[i + 1][k];

                // Take current interval
                Node take = dp[nxt[i]][k - 1];

                take.score += arr[i][2];

                // Add original index
                take.indices.push_back(arr[i][3]);

                // Keep indices sorted
                sort(take.indices.begin(), take.indices.end());

                if (better(take, skip)) {
                    dp[i][k] = take;
                }
                else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].indices;
        
    }
};