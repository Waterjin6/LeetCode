class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
        int ns = nums.size();
        vector<int> dp(ns, 0);

        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for(int i = 2; i < ns; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            for(int k = i-3; k >= 0; k--) dp[i] = max(dp[i], dp[k]+nums[i]);
        }
        
        return dp[ns-1];
    }
};