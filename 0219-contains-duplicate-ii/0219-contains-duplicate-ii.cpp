class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        int n;
        for(int i = 0; i < nums.size(); i++){
            n = m[nums[i]].size();
            if(n > 0 && i - m[nums[i]][n-1] <= k)return true;
            m[nums[i]].push_back(i);
        }
        
        return false;
    }
};