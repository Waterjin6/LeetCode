class Solution {
public:
    vector<vector<int>> ans;
    
    void getSub(vector<int>& nums, int &end, int idx, vector<int> v){
        if(idx == end){
            ans.push_back(v);
            return;
        }
        
        getSub(nums, end, idx+1, v);
        v.push_back(nums[idx]);
        getSub(nums, end, idx+1, v);
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        getSub(nums, n, 0, v);
        return ans;    
    }
};