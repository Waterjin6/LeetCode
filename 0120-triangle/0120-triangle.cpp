class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size()-2; i >= 0; i--){
            for(int t = 0; t < triangle[i].size(); t++){
                triangle[i][t] += min(triangle[i+1][t], triangle[i+1][t+1]);
            }
        }
        return triangle[0][0];
    }
};