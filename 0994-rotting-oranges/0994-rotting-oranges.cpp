class Solution {
public:
    int inRange(int &x, int &y, int &xs, int &ys){
        return x >= 0 && x<xs && y >= 0 && y < ys;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, xs = grid.size(), ys = grid[0].size();
        int dx[4] = {-1,1,0,0}; // u, d, l, r
        int dy[4] = {0,0,-1,1};
        
        queue<pair<int,int>> ro;
        
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(grid[i][t] == 2) ro.push({i,t});        
            }        
        }
        
        if(ro.empty()){
            for(int i = 0; i < xs; i++){
                for(int t = 0; t < ys; t++){
                    if(grid[i][t] == 1) return -1;        
                }        
            }
            return 0;
        }
        
        int rs, rx, ry, nx, ny, cs, rotate = 0;
        
        while(!ro.empty()){
            cs = 0;
            rs = ro.size();
            //cout<< rs<<endl;
            for(int i = 0; i < rs; i++){
                tie(rx,ry) = ro.front();
                //cout<< rx<<" "<<ry<<endl;
                grid[rx][ry] = 2;
                ro.pop();
                
                for(int t = 0; t < 4; t++){
                    nx = rx+dx[t];
                    ny = ry+dy[t];
                    //cout<< "nx : "<< nx << ", ny : "<< ny <<endl; 
                    if(inRange(nx, ny, xs, ys)&&grid[nx][ny] == 1){
                        //cout<<"hey"<<endl;
                        //cout<< "nx : "<< nx << ", ny : "<< ny <<endl; 
                        cs++;
                        grid[nx][ny] = 2;
                        ro.push({nx,ny});
                    }
                }
            }
            //cout<<endl;
            rs = cs;
            //cout<< "rs : "<< rs<<endl;
            rotate++;
            
        }
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(grid[i][t] == 1) return -1;        
            }        
        }
        
        return rotate-1;
    }
};