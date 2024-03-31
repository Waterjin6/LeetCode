class Solution {
public:
    int dx[4] = {-1,1,0,0}; // u d l r
    int dy[4] = {0,0,-1,1};
    
    void paint(int x, int y, vector<vector<int>>& grid, int &xs, int &ys){
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = 0;
        int qx,qy, cx, cy;
        
        while(!q.empty()){
            tie(qx,qy) = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                cx = qx+ dx[i];
                cy = qy+dy[i];
                
                if(min(cx, cy) >= 0 && cx < xs && cy< ys && grid[cx][cy] == 1){
                    grid[cx][cy] = 0;
                    q.push({cx,cy});
                }
            }        
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int xs = grid.size(), ys = grid[0].size();
        
        for(int i = 0; i < xs; i++){
            if(grid[i][0] == 1)paint(i,0,grid, xs, ys);
            if(grid[i][ys-1] == 1)paint(i, ys-1,grid, xs, ys);
        }
        
        for(int i = 0; i < ys; i++){
            if(grid[0][i] == 1)paint(0, i, grid, xs, ys);
            if(grid[xs-1][i] == 1)paint(xs-1, i, grid, xs, ys);
        }
        
        int ans = 0;
        for(int i = 1; i < xs-1; i++){
            for(int t = 1; t < ys-1; t++){
                if(grid[i][t] == 1)ans++;
            }
        }
        return ans;
    }
};