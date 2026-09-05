class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size()-1;
        int res;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[nums.size()-1])
                low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }
        return nums[res];
        
    }
};