class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> newM;
        
        for(int i = 0; i < matrix.size(); i++){
            vector<int> v;
            for(int t= 0; t < matrix[0].size(); t++){
                v.push_back(matrix[matrix.size()-1-t][i]);
            }
            newM.push_back(v);
        }
        
        matrix = newM;
        
        return;
    }
};