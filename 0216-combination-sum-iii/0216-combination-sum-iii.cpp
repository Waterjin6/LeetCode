class Solution {
public:
    vector<vector<int>> ans;
    
    void makeSum(int n, int c, vector<int> v, int s){
        if(c == 0){
            if(s == 0) ans.push_back(v);
            return;
        }
        if(n < 1)return;
        
        for(int i = n; i >= 1; i--){
            if(i > s) continue;
            v.push_back(i);
            makeSum(i-1, c-1, v, s-i);
            v.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        
        for(int i = 9; i >= 1; i--){
            if(i > n) continue;
            v.push_back(i);
            makeSum(i-1, k-1, v, n-i);
            v.pop_back();
        }
        
        return ans;
    }
};