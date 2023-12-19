class Solution {
public:
    void get(int &cnt, int &sum, int x, int y, vector<vector<int>>& img){
        cnt = 1;
        sum = img[x][y];
        int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1}; // lu u ru l r ld d rd
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int nx, ny;
        for(int i = 0; i < 8; i++){
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx < 0 || nx >= img.size() || ny < 0 || ny >= img[0].size())continue;
            cnt++;
            sum += img[nx][ny];
        }
        return;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));
        
        int cnt, sum;
        
        for(int i = 0; i < img.size(); i++){
            for(int t = 0; t < img[0].size(); t++){
                get(cnt, sum, i, t, img);
                ans[i][t] = sum / cnt;
            }
        }
        return ans;
    }
};