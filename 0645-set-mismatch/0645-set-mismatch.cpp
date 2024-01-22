class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++){
            if(cnt[i] == 2)ans.push_back(i);
        }
        for(int i = 1; i <= nums.size(); i++){
            if(cnt[i] == 0)ans.push_back(i);
        }
        return ans;
    }
};