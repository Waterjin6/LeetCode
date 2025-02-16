class Solution {
public:
    bool isValid(int x, int y, int &xs, int &ys){
        return (x >= 0) && (y >= 0) && (x < xs) && (y < ys);
    }
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int ms = heights.size(), ns = heights[0].size(),cx, cy, nx, ny;

        vector<vector<bool>> isPac(ms, vector<bool>(ns, false));
        vector<vector<bool>> isAtl(ms, vector<bool>(ns, false));

        queue<pair<int,int>> q;

        // Check Pacific
        for(int i = 0; i < ns; i++) {
            q.push({0,i});
            isPac[0][i] = true;
        }

        for(int i = 1; i < ms; i++){
            q.push({i,0});
            isPac[i][0] = true;
        }

        while(!q.empty()){
            cx = q.front().first;
            cy = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                nx = cx+dir[i][0];
                ny = cy+dir[i][1];

                if(isValid(nx,ny, ms, ns) && heights[nx][ny] >= heights[cx][cy] && isPac[nx][ny] == false){
                    isPac[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }

        // Check Atlantic Ocean
        for(int i = 0; i < ns; i++) {
            q.push({ms-1,i});
            isAtl[ms-1][i] = true;
        }

        for(int i = 0; i < ms-1; i++){
            q.push({i,ns-1});
            isAtl[i][ns-1] = true;
        }
        

        while(!q.empty()){
            cx = q.front().first;
            cy = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                nx = cx+dir[i][0];
                ny = cy+dir[i][1];

                if(isValid(nx,ny, ms, ns) && heights[nx][ny] >= heights[cx][cy] && isAtl[nx][ny] == false){
                    isAtl[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }

        /*cout<<endl;
        for(int i = 0; i < ms; i++){
            for(int t = 0; t < ns; t++){
                cout<< isAtl[i][t]<<" ";
            }
            cout<<endl;
        }*/
        /*cout<<endl;
        for(int i = 0; i < ms; i++){
            for(int t = 0; t < ns; t++){
                cout<< cnt[i][t]<<" ";
            }
            cout<<endl;
        }
*/
        for(int i = 0; i < ms; i++){
            for(int t = 0; t < ns; t++){
                if(isAtl[i][t] && isPac[i][t])ans.push_back({i,t});
            }
        }
        return ans;
    }
};