class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int sz = grid.size(), qs, x, y, nx, ny, cnt = 1;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

        vector<vector<bool>> visited(sz, vector<bool>(sz, 0));
        queue<pair<int,int>> q;

        if(grid[0][0] == 1 || grid[sz-1][sz-1] == 1)return -1;
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            qs = q.size();
            for(int i = 0; i < qs; i++){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                
                //cout<< x <<" "<<y<<endl;
                if(x == sz-1 && y == sz-1)return cnt;

                for(int t = 0; t < 8; t++){
                    nx = x + dir[t][0];
                    ny = y + dir[t][1];

                    if(nx < 0 || ny < 0 || nx == sz || ny == sz) continue;
                    if(visited[nx][ny] == true)continue;
                    visited[nx][ny] = true;

                    if(grid[nx][ny] == 0)q.push({nx,ny});
                }
            }
            cnt++;
        }


        return -1;
    }
};