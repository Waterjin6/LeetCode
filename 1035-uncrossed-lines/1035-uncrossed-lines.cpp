class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
        
        for(int i = 0; i < s1; i++){
            for(int t = 0; t < s2; t++){
                if(nums1[i] == nums2[t]) dp[i+1][t+1] = 1 + dp[i][t];
                else dp[i+1][t+1] = max(dp[i][t+1], dp[i+1][t]);
            }
        }
        
        return dp[s1][s2];
    }
};