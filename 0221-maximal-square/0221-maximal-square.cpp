class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, hei = matrix.size(), wid = matrix[0].size();
        vector<vector<int>> dp(hei, vector<int>(wid, 0));
        
        for(int i = 0; i < hei; i++) dp[i][0] = matrix[i][0] - '0';
        for(int i = 0; i < wid; i++) dp[0][i] = matrix[0][i] - '0';
        
        for(int i = 1; i < hei; i++){
            for(int t = 1; t < wid; t++){
                if(matrix[i][t] == '1') dp[i][t] = min(dp[i-1][t-1], min(dp[i-1][t], dp[i][t-1]))+1;
            }
        }
        
        for(int i = 0; i < hei; i++){
            for(int t = 0; t < wid; t++){
                //cout<< dp[i][t]<<" ";
                ans = max(ans, dp[i][t]);
            }
            //cout<<endl;
        }
        
        return ans*ans;
    }
    
};