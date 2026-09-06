class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while(low<= high){
            int mid = (low+high)/2;
            long long hrs = 0;
            for(int i = 0; i < n; i++){
                hrs = hrs+piles[i]/mid;
                if(piles[i] % mid != 0)
                    hrs++;
            }
            if(hrs > h)
                low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }

        return res;
        
    }
};