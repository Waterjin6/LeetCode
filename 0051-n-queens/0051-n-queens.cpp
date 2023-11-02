class Solution {
public:
    vector<vector<string>> ans;
    int dx[4] = {-1,-1};
    int dy[4] = {-1,1};
    
    bool inRange(int x, int y, int sz){
        return x >= 0 && y >= 0 && x < sz && y < sz;
    }
    
    bool isPossible(int x, int y, vector<string> v){
        for(int i = 0; i < v.size(); i++){
            if(v[i][y] == 'Q')return false;
        }
        for(int t = 0; t < 2; t++){
            for(int i = 0; inRange(x+dx[t]*i, y+dy[t]*i, v.size()) == true; i++){
                if(v[x+dx[t]*i][y+dy[t]*i]== 'Q')return false;
            }
        }
        
        return true;
    }
    
    void putQueen(int x, int totalQ, vector<string> &v)
    {
        if(x == totalQ){
            ans.push_back(v);
            return;
        }
        
        for(int y = 0; y < totalQ; y++){
            if(isPossible(x,y,v)){
                v[x][y] = 'Q';
                putQueen(x+1,totalQ, v);
                v[x][y] = '.';
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string (n,'.'));

        bool visited[9] = {0,};
        putQueen(0,n,v);
        
        return ans;
    }
};