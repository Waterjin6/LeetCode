//class Solution {
//private:
    /*void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

*/
class Solution {
public:
    vector<vector<string>> ans;
    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,-1,1};
    
    bool inRange(int x, int y, int sz){
        return x >= 0 && y >= 0 && x < sz && y < sz;
    }
    
    bool isPossible(int x, int y, vector<string> v){
        
        for(int t = 0; t < 4; t++){
            for(int i = 0; inRange(x+dx[t]*i, y+dy[t]*i, v.size()) == true; i++){
                if(v[x+dx[t]*i][y+dy[t]*i]== 'Q')return false;
            }
        }
        
        return true;
    }
    
    void putQueen(int queenCnt, int x, int totalQ, vector<string> &v, bool isVisitedY[])
    {
        if(queenCnt == totalQ){
            ans.push_back(v);
            return;
        }
        if(x >= totalQ)return;
        
        for(int y = 0; y < totalQ; y++){

            if((isVisitedY[y] == 0)&&(isPossible(x,y,v))){
                v[x][y] = 'Q';
                isVisitedY[y] = 1;
                putQueen(queenCnt+1,x+1,totalQ, v, isVisitedY);
                v[x][y] = '.';
                isVisitedY[y] = 0;
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string (n,'.'));

        bool visited[9] = {0,};
        putQueen(0,0,n,v, visited);
        
        return ans;
    }
};