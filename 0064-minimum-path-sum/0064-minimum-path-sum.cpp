class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int u, l;
        
        for(int i = 0; i < grid.size(); i++){
            for(int t = 0; t < grid[0].size(); t++){
                if(i == 0 && t== 0)continue;
                u = (i-1 >= 0) ? grid[i-1][t] : INT_MAX;
                l = (t-1 >= 0) ? grid[i][t-1] : INT_MAX;
                grid[i][t] += min(u,l);
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};