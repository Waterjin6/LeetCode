class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int xs = grid.size(), ys = grid[0].size();
        
        vector<int> oRCnt(xs, 0);
        vector<int> oCCnt(ys, 0);
        
        vector<vector<int>> diff(xs, vector<int>(ys, 0));
        
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                if(grid[i][t] == 1) {
                    oRCnt[i]++;
                    oCCnt[t]++;
                }
            }
        }
        
        for(int i = 0; i < xs; i++){
            for(int t = 0; t < ys; t++){
                diff[i][t] = oRCnt[i] + oCCnt[t] - (xs-oRCnt[i]) - (ys - oCCnt[t]);
            }
        }
        
        return diff;
    }
};