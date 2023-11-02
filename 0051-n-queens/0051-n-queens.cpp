class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPossible(int x, int y, vector<string> &v){
        for(int i = 0; i < v.size(); i++){
            if(v[i][y] == 'Q')return false;
        }
        
        for(int i = 1; (x-i >=0) && (y-i>=0); i++){
            if(v[x-i][y-i]== 'Q')return false;
        }
        
        for(int i = 1; x-i >=0 && y+i < v.size(); i++){
            if(v[x-i][y+i]== 'Q')return false;
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