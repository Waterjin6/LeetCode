class Solution {
public:
    bool isPossible(int &x, int &y, int &xs, int &ys){
        return x >= 0 && x < xs && y >= 0 && y < ys;
    }
    
    bool isBorder(int &x, int &y, int &xs, int &ys){
        return x == 0 || x == xs-1 || y == 0 || y == ys-1;
    }
    
    int dx[4] = {-1,1, 0, 0}; // u, d, l, r
    int dy[4] = {0,0, -1,1};
            
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int,int,int>> q; // x, y, cnt
        q.push({entrance[0], entrance[1], 0});

        int x, y, c, nx, ny, xs = maze.size(), ys = maze[0].size();
        vector<vector<bool>> isVisited(maze.size(), vector<bool>(maze[0].size(), 0));
        isVisited[entrance[0]][entrance[1]] = 1;
        
        while(!q.empty()){
            tie(x,y,c) = q.front();
            q.pop();
            if(c != 0 && isBorder(x,y,xs,ys)){
                //cout<< x <<" "<<y<<endl;
                return c;
            }
            
            for(int i = 0; i < 4; i++){
                nx = x+dx[i];
                ny = y+dy[i];
                if(isPossible(nx, ny,xs,ys) && maze[nx][ny] == '.' && isVisited[nx][ny] == false){
                    isVisited[nx][ny] = true;
                    q.push({nx,ny,c+1});
                }
            }
        }
        
        return -1;
    }
};