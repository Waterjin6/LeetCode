class Solution {
public:
    vector<vector<int>> ans;
    
    void getCom(int p, int &n, int &k, vector<int> &v){
        if(v.size()== k){
            ans.push_back(v);
            return;
        }
        if(p == n+1)return;
        
        v.push_back(p);
        getCom(p+1, n, k, v);
        
        v.pop_back();
        getCom(p+1, n, k, v);
        return;
    } 
    
    vector<vector<int>> combine(int n, int k) {
        if(n == 1 && k == 1)return {{1}};
        vector<int> v;
        getCom(1, n, k, v);
        return ans;    
    }
};