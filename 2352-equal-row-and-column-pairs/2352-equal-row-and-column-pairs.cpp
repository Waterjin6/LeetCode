class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
        int answer = 0;
        int isSame = 1;
        
        for(int i = 0; i < grid.size(); i++){ // row to compare
            
            for(int t = 0; t < grid.size(); t++){ // column to compare
                isSame = 1;
                
                for(int k = 0; k < grid.size(); k++){ // route
                    if(grid[i][k] != grid[k][t]){
                        isSame = 0;
                        break;
                    }
                }
                if(isSame == 1){
                    isSame = 0;
                    answer++;
                }
            }
        }
        return answer;
    }
};