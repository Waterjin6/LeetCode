class Solution {
public:
    int findMax(int x, int y, int sz, vector<vector<int>>& grid){
        int ans = INT_MIN;
        
        for(int i = 0; i < 3 && x-1+i < sz; i++){
            for(int t = 0; t < 3 && y-1+t < sz; t++) ans = max(ans, grid[x-1+i][y-1+t]);
        }
        
        return ans;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int sz = grid.size()-2;
        
        vector<vector<int>> ans(sz, vector<int>(sz));
        
        for(int i = 0; i < sz; i++){
            for(int t = 0; t < sz; t++){
                ans[i][t] = findMax(i+1, t+1, sz+2, grid);
            }
        }
        
        return ans;
    }
};