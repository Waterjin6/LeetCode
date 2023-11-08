class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x;
        vector<int> y;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int t = 0; t < matrix[0].size(); t++){
                if(matrix[i][t] == 0){
                    x.push_back(i);
                    y.push_back(t);
                }
            }
        }
        
        for(int i = 0; i < x.size(); i++){
            for(int t = 0; t < matrix[0].size(); t++){
                matrix[x[i]][t] = 0;
            }
        }
        
        for(int i = 0; i < y.size(); i++){
            for(int t = 0; t < matrix.size(); t++){
                matrix[t][y[i]] = 0;
            }
        }
        
        return;
    }
};