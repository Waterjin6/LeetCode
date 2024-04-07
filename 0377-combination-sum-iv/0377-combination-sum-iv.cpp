class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> ans(target+1, 0);
        ans[0] = 1;
        
        for(int x = 1; x <= target; x++){
            for(int t: nums){
                if(x-t >= 0) ans[x] += ans[x-t];
            }
        }
        
        return ans[target];
    }
};