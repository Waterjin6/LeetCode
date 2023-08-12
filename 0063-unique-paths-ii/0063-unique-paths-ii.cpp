class Solution {
public:
    vector<vector<int>> obstacleGrid;
    int sizeX, sizeY;
    int dp[100][100] = {0, };
    
    int move(int x, int y){
        if((x >= sizeX)||(y >= sizeY)||(obstacleGrid[x][y] == 1))return 0;
        
        if((x == sizeX-1)&&(y == sizeY-1))return 1;
        
        if(dp[x][y] != 0) return dp[x][y];
        
        dp[x][y] = move(x+1, y) + move(x, y+1);
        return dp[x][y];
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->sizeX = obstacleGrid.size();
        this->sizeY = obstacleGrid[0].size();
        
        if((obstacleGrid[0][0] == 1)&&(obstacleGrid[sizeX-1][sizeY-1] == 1))return 0;
        
        this->obstacleGrid = obstacleGrid;
        
        return move(0,0);
    }
};