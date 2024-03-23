class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int x : nums) sum += x;
        
        if(sum % 2 == 1)return false;
        
        sum /= 2;
        
        sort(nums.begin(), nums.end());
        
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, 0));
        
        for(int i = 0; i < nums.size(); i++) dp[i][0] = 1;
        //for(int i = 1; i <= sum; i++) dp[0][i] = 0;
        
        for(int i = 1; i < nums.size(); i++){
            for(int t = 1; t <= sum; t++){
                dp[i][t] = dp[i-1][t];
                if(nums[i] <= t) dp[i][t] = dp[i][t] || dp[i-1][t-nums[i]];
            }
        }

        return dp[nums.size()-1][sum];
    }
};