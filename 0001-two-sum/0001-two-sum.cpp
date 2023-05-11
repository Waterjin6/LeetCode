class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size()-1; i++){
            for(int t = i+1; t < nums.size(); t++){
                if(nums[i] + nums[t] == target){
                    ans.push_back(i);
                    ans.push_back(t);
                    return ans;
                }
            }
        }
        return ans;
    }
};