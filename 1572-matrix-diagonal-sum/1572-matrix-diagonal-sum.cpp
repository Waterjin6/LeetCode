class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, s = mat.size();
        
        for(int i = 0; i < s; i++) {
            ans += mat[i][i];
            ans += mat[s-1-i][i];
        }
        if(s % 2 == 1)ans -= mat[s/2][s/2];
        return ans;
    }
};