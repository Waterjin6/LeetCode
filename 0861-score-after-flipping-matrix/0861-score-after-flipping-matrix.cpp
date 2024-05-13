class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0, xs = grid.size(), ys = grid[0].size(), cnt1 = 0, two = 0;
        
        // change row
        for(int i = 0; i < xs; i++){
            if(grid[i][0] == 0) for(int t = 0; t < ys; t++) grid[i][t] = grid[i][t] ^ 1;
        }

        // change col
        for(int i = 0; i < ys; i++){
            // calc cnt
            cnt1 = 0;
            for(int t = 0; t < xs; t++) if(grid[t][i] == 1)cnt1++;
            
            if(2*cnt1 >= xs) continue;
            
            for(int t = 0; t < xs; t++) grid[t][i] = grid[t][i] ^ 1;
        }
        
        // calc ans
        for(int i = ys-1; i >= 0; i--){
            for(int t = 0; t < xs; t++) ans += grid[t][i] * pow(2, two);
            two++;
        }
        return ans;
    }
};