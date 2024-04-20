class Solution {
public:
    vector<int> getBound(int &x, int &y, int &xs, int &ys, vector<vector<int>> &land){
        vector<int> ans = {x, y, x, y};
        
        while(ans[2] < xs && land[ans[2]][y] == 1) ans[2]++;
        while(ans[3] < ys && land[x][ans[3]] == 1) ans[3]++;
        ans[2]--;
        ans[3]--;
        
        for(int i = x; i <= ans[2]; i++){
            for(int t = y; t <= ans[3]; t++) land[i][t] = 0;
        }
        
        return ans;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int xs = land.size(), ys = land[0].size();
        
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(land[i][t] == 1) ans.push_back(getBound(i,t, xs, ys, land));
            }
        }
        
        return ans;
    }
};