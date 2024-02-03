class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int t = 0; t < grid[0].size(); t++){
                if(grid[i][t] == 1){
                    if(i-1 == -1 || grid[i-1][t] == 0)ans++;
                    if(i+1 == grid.size() || grid[i+1][t] == 0)ans++;
                    if(t-1 == -1 || grid[i][t-1] == 0)ans++;
                    if(t+1 == grid[0].size() || grid[i][t+1] == 0)ans++;
                }
            }
        }
        return ans;
    }
};