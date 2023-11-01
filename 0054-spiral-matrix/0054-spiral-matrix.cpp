class Solution {
public:
    vector<int> ans;
    vector<vector<int>> matrix;
    int wid, hei;
        
    int dx[4] = {0,1,0,-1}; // right, down, left, up
    int dy[4] = {1,0,-1,0};
    
    
    bool isPossible(int x, int y){
        return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size();
    }
    
    
    void changeDir(int &wid, int &hei, int &x, int &y, int &d, int &dw, int &dh){
        //cout<<"wid : "<<wid <<endl;
        if (d % 2 == 0)dw++;
        else if (d % 2 == 1)dh++;
        
        if((dw == wid)){
            //cout<<"x : "<<x <<", y : "<< y<<endl;
            d = (d+1)%4;
            wid--;
            dh = 0;
        }
        else if((matrix.size() != 1)&&(dh == hei)){
            //cout<<"change hei dh : "<<dh <<" hei"<<hei<<" size : "<<matrix.size()<<endl;
            d = (d+1)%4;
            hei--;
            dw = 0;
        }
        
        x += dx[d];
        y += dy[d];
        //cout<<"x : "<<x <<", y : "<< y<< ", matrix : "<<matrix[x][y]<<endl;
        return;
    }
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        wid = matrix[0].size(), hei = matrix.size()-1;
        this->matrix = matrix;
        
        int x = 0, y = 0, d = 0, dw = 0, dh = 0;
        
        while(isPossible(x,y)&&(matrix[x][y] != 101)){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = 101;
            
            changeDir(wid,hei, x, y, d, dw, dh);
        }
        
        return ans;
        
    }
};