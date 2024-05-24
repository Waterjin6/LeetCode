class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isIsland(int &x, int &y, vector<vector<int>>& grid, int &xs, int &ys){
        bool ans = true;
        int qx,qy,cx, cy;
        
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = 1;
        
        while(!q.empty()){
            qx = q.front().first;
            qy = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                cx = qx + dx[i];
                cy = qy + dy[i];
                
                if(min(cx,cy) < 0 || cx >= xs || cy >= ys) continue;
                
                if(grid[cx][cy] == 0){
                    grid[cx][cy] = 1;
                    q.push({cx,cy});
                    
                    if(cx == 0 || cy == 0 || cx == xs-1 || cy == ys-1) ans = false;
                }
            }
        }
        return ans;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0, xs = grid.size(), ys = grid[0].size();
        
        for(int i = 1; i < xs-1; i++){
            for(int t = 1; t < ys-1; t++){
                if(grid[i][t] == 0 && isIsland(i,t, grid, xs, ys)) ans++;
            }
        }
        return ans;
    }
};