class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int sz = nums.size();
        //vector<int> ans(sz, -1);

        //ans[sz-1] = nums[sz-1];

        // multiply
        for(int i = 0; i < sz-1; i++){
            if(nums[i] == nums[i+1]) {
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        vector<int> ans;

        // shift 0
        for(int i = 0; i < sz; i++){
            if(nums[i] != 0) ans.push_back(nums[i]);
        }

        while(ans.size() < sz) ans.push_back(0);

        return ans;
    }
};