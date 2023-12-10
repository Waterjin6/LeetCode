class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix[0].size(), vector<int>(matrix.size()));
        
        for(int i = 0; i < matrix[0].size(); i++){
            for(int t = 0 ; t < matrix.size(); t++)v[i][t] = matrix[t][i];
        }
        
        return v;
    }
};