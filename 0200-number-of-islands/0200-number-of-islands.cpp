class Solution {
public:
    bool inRange(int &x, int &y, int &xs, int &ys){
        return x >= 0 && x < xs && y >= 0 && y < ys;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int xs = grid.size(), ys = grid[0].size();
        queue<pair<int,int>> q;
        
        int dx[4] = {-1, 1, 0, 0}; //u d l r
        int dy[4] = {0,0, -1, 1};
        
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(grid[i][t] == '0')continue;
                q.push({i,t});
                grid[i][t] = '0';
                ans++;
                int x,y, nx, ny;
                
                while(!q.empty()){
                    tie(x,y)= q.front();
                    q.pop();
                    
                    for(int r = 0; r < 4; r++){
                        nx = x+dx[r]; ny = y+dy[r];
                        if(inRange(nx,ny, xs, ys) && grid[nx][ny] == '1'){
                            grid[nx][ny] = '0';
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};