class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> strength_idx;
        int cnt = 0;
        
        for(int i = 0; i < mat.size(); i++){
            cnt = 0;
            for(int t = 0; t < mat[i].size(); t++) cnt += mat[i][t];
            strength_idx.push({cnt, i});
        }
        
        while(k-- > 0){
            ans.push_back(strength_idx.top().second);
            //cout<< strength_idx.top().second<<" "<<strength_idx.top().first<<endl;
            strength_idx.pop();
        }
        return ans;
    }
};