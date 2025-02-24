class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), cx, cy, nx, ny;
        vector<vector<int>> dir = {{1,0},{-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        vector<vector<bool>> isVisited(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++){
            for(int t = 0; t < n; t++){
                if(mat[i][t] == 0){
                    q.push({i,t});
                    isVisited[i][t] = true;
                }
            }
        }

        while(!q.empty()){
            cx = q.front().first;
            cy = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                nx = cx+dir[i][0];
                ny = cy+dir[i][1];

                if(nx < 0 || nx == m || ny < 0 || ny == n || isVisited[nx][ny] == true) continue;
                q.push({nx,ny});
                isVisited[nx][ny] = true;
                mat[nx][ny] = mat[cx][cy]+1;
            }
        }
        return mat;
    }
};