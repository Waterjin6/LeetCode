class Solution {
public:
    vector<vector<int>> ans;
    
    void permu(int pos, int &n, int visited[], vector<int> &v, vector<int>& nums){
        if(pos == n){
            ans.push_back(v);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                v.push_back(nums[i]);
                
                permu(pos + 1, n, visited, v, nums);
                
                v.pop_back();
                visited[i] = 0;
            }
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int visited[8] = {0,}, n = nums.size();
        vector<int> v;
        permu(0, n, visited, v, nums);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        return ans;
    }
};