class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; // u d l r
    int dy[4] = {0, 0, -1, 1};
    
    void getAns(vector<vector<int>>& grid, int &cx, int &cy, int &m, int &n, int sum, int &ans){
        int nx, ny, x;
        
        for(int i = 0; i < 4; i++){
            nx = cx + dx[i];
            ny = cy + dy[i];
            
            if(nx == -1 || ny == -1 || nx == m || ny == n || grid[nx][ny] == 0)continue;
            x = grid[nx][ny];
            grid[nx][ny] = 0;
            getAns(grid, nx, ny, m, n, sum+x, ans);
            grid[nx][ny] = x;
        }
        if(ans < sum) ans = sum;
        return;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), x;
        
        for(int i = 0; i < m; i++){
            for(int t = 0; t < n; t++){
                if(grid[i][t] != 0){
                    x = grid[i][t];
                    grid[i][t] = 0;
                    getAns(grid, i, t, m, n, x, ans);
                    grid[i][t] = x;
                }
            }
        }
        return ans;
    }
};