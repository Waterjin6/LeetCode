class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ns = size(nums);
        int f = INT_MAX, s = INT_MAX;
        
        for (int i = 0; i < ns; i++){
            if(nums[i] <= f) f = nums[i];
            else if(nums[i] <= s) s= nums[i];
            else return true;
        }
        return false;
    }
};