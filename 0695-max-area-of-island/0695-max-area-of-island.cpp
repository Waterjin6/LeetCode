class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {-1,0},{1,0}};

    int getSize(int x, int y, int &xs, int &ys, vector<vector<int>>& grid){
        int ans = 1, cx, cy, qx, qy;
        //bool isBorder = false;

        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = 0;

        while(!q.empty()){
            qx = q.front().first;
            qy = q.front().second;
            q.pop();

            //if(qx == 0 || qx == xs-1 || qy == 0 || qy == ys-1) isBorder = true;

            for(int i = 0; i < 4; i++){
                cx = qx + dir[i][0];
                cy = qy + dir[i][1];

                if(cx < 0 || cy < 0 || cx == xs || cy == ys || grid[cx][cy] == 0) continue;
                q.push({cx,cy});
                grid[cx][cy] = 0;
                ans++;
            }
        }


        //if(isBorder == true) return 0;
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ms = grid.size(), ns = grid[0].size(), ans = 0;
        
        vector<vector<bool>> isVisited(ms, vector<bool>(ns, false));

        for(int i = 0; i < ms; i++){
            for(int t = 0; t < ns; t++){
                if(grid[i][t] == 1) {
                    ans = max(ans, getSize(i,t, ms, ns, grid));
                    //cout<< "i : "<<i <<" , t : "<<t << ", ans : "<<ans<<endl;
                }
            }
        }

        return ans;
    }
};