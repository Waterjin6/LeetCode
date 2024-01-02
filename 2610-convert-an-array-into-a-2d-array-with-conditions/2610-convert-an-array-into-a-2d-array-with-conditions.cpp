class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int mCnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            if(mCnt < cnt[nums[i]]) mCnt = cnt[nums[i]];
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < mCnt; i++){
            vector<int> v;
            ans.push_back(v);
        }
        
        for(auto i = cnt.begin(); i != cnt.end(); i++){
            for(int t = 0; t < i->second; t++){
                ans[t].push_back(i->first);
            }
        }
        return ans;
    }
};