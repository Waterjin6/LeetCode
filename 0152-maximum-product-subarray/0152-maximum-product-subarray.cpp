class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxRes = nums[0], minRes = nums[0], ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(maxRes, minRes);
            maxRes = max(maxRes*nums[i], nums[i]);
            minRes = min(minRes*nums[i], nums[i]);
            ans = max(maxRes, ans);
        }
        
        return ans;
    }
};