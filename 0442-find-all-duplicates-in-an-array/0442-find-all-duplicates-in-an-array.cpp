class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int x : nums){
            if(m[x] == 0) m[x]++;
            else ans.push_back(x);
        }
        return ans;
    }
};