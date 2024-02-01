class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()/3; i++){
            if(nums[3*i+2]-nums[3*i] > k)return {};
            ans.push_back({nums[3*i], nums[3*i+1], nums[3*i+2]});
        }
        return ans;
    }
};