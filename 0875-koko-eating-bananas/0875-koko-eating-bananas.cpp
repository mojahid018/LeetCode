class Solution {
public:

        // Returns total hours needed at speed k
    long long hours(vector<int>& piles, int k) {
        long long hrs = 0;

        for (int i = 0; i < piles.size(); i++) {
            hrs += piles[i] / k;

            if (piles[i] % k != 0)
                hrs++;
        }

        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int res = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (hours(piles, mid) > h) {
                // Speed is too slow
                low = mid + 1;
            }
            else {
                // Speed works, try smaller
                res = mid;
                high = mid - 1;
            }
        }

        return res;
        
    }
};