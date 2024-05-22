class Solution {
public:
    queue<pair<int,int>> q;
    
    int dx[4] = {-1, 1, 0,0};
    int dy[4] = {0, 0, -1, 1};
    
    void makeIsland2(int &x, int &y, int &n, vector<vector<int>>& grid){
        q.push({x,y});
        grid[x][y] = 2;
        int cx,cy;
        
        for(int i = 0; i < 4; i++){
            cx = x+dx[i];
            cy = y+dy[i];
            
            if(min(cx,cy) >= 0 && max(cx,cy) < n && grid[cx][cy] == 1){
                makeIsland2(cx,cy, n, grid);
            }
        }
        
        return;
    }
    
    void findFirstIsland(int &n, vector<vector<int>>& grid){
        for(int i = 0; i < n; i++){
            for(int t = 0; t < n; t++){
                if(grid[i][t] == 1){
                    makeIsland2(i,t,n,grid);
                    return;
                }
            }
        }
        return;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int N = grid.size(), x, y,cx,cy;
        
        // 첫번째 섬 찾아서 2로 바꾸기
        findFirstIsland(N, grid);
        /*for(int i = 0; i < N; i++){
            for(int t = 0; t < N; t++){
                cout<< grid[i][t]<<" ";
            }
            cout<<endl;
        }*/
        // 근접한 1 가장 가까운거 찾기
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            //cout<< x<<" "<<y<<endl;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                cx = x+dx[i];
                cy = y+dy[i];
            
                if(min(cx,cy) >= 0 && max(cx,cy) < N){
                    if(grid[cx][cy] == 1) return grid[x][y]-2;
                    else if(grid[cx][cy] == 0){
                        grid[cx][cy] = grid[x][y]+1;
                        q.push({cx,cy});
                    }
                }
            }
        }
        return 0;
    }
};