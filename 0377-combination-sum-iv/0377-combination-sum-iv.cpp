class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> ans(target+1, 0);
        ans[0] = 1;
        
        for(int x = 1; x <= target; x++){
            for(int t: nums){
                if(x-t >= 0){
                    //if(ans[nums[x]]+ans[nums[x]-t] >= INT_MAX)continue;
                    ans[x] += ans[x-t];
                }
            }
        }
        /*for(int x : nums){
            for(int t = x; t <= target; t++){
                ans[t] += 1+ans[t-x];
            }
        }*/
        
        return ans[target];
    }
};