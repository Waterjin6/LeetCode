class Solution {
public:
    vector<vector<int>> ans;
    
    void getAns(int idx, vector<int>& unique, unordered_map<int,int> &cnt, vector<int> v){

        if(idx == unique.size()){
            if(find(ans.begin(),ans.end(),v) == ans.end())ans.push_back(v);
            return;
        }
        
        getAns(idx+1, unique, cnt, v);

        for(int i = 1; i <= cnt[unique[idx]]; i++){
            v.push_back(unique[idx]);
            getAns(idx+1, unique, cnt, v);
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> uniq, v;
        unordered_map<int,int> cnt;
    
        for(int i = 0; i < nums.size(); i++){
            if(cnt[nums[i]] == 0)uniq.push_back(nums[i]);
            cnt[nums[i]]++;
        }
        getAns(0, uniq, cnt, v);
        return ans;
    }
};