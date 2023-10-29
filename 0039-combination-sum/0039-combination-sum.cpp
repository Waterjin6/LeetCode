class Solution {
public:
    int target;
    vector<vector<int>> ans;
    vector<int> candidates;
    
    void work(int startIdx, vector<int> &vec, int sum){
        if(sum == target){
            ans.push_back(vec);
            return;
        }
        
        for(int i = startIdx; (i < candidates.size())&&(sum + candidates[i] <= target); i++){
            vec.push_back(candidates[i]);
            work(i,vec,candidates[i]+sum);
            vec.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;    
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        
        for(int i = 0; (i < candidates.size()&&(candidates[i] <= target)); i++){
            vector<int> v = {candidates[i]};
            work(i, v ,candidates[i]);
        }
 
        return ans;
    }
};