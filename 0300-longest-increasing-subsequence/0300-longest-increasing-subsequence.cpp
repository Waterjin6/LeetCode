class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0, ns = nums.size();
        
        vector<int> cnt(ns, 0);
        
        for(int i = ns-1; i >= 0 && ans < ns-i; i--){
            for(int t = i+1; t < ns; t++){
                if(nums[i] < nums[t]){
                    cnt[i] = max(cnt[t]+1, cnt[i]);                    
                }
            }
            ans = max(ans, cnt[i]+1);
        }
        
        return ans;
    }
};