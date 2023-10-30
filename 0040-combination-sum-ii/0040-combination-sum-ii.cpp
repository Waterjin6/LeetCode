class Solution {
public:
    int target;
    int cnt[51] = {0,};
    
    vector<vector<int>> ans;
    
    void work(int need, int startIdx, vector<int> vec){
        
        if(need == 0){
            ans.push_back(vec);
            return;
        }
        
        if(startIdx > need)return;
        
        while((startIdx <= target)&&(cnt[startIdx] == 0))startIdx++;
        if(startIdx > target)return;
            
        int mx = (startIdx*cnt[startIdx] >= need) ? need/startIdx : cnt[startIdx];
            
        for(int t = 0; t <= mx; t++){
            work(need - t*startIdx, startIdx+1, vec);
            vec.push_back(startIdx);
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target; 
  
        for(int i = 0; i < candidates.size(); i++) cnt[candidates[i]]++;
        
        vector<int> v;
        work(target, 1 , v);
 
        return ans;
    }
};