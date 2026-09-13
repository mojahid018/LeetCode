class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        map<pair<int, int>, int> mp;

        // Store positions of 1s in img1
        vector<pair<int, int>> a;
        vector<pair<int, int>> b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        int ans = 0;

        // Compare every 1 in img1 with every 1 in img2
        for (auto p1 : a) {
            for (auto p2 : b) {

                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;

                mp[{dx, dy}]++;

                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
        
    }
};