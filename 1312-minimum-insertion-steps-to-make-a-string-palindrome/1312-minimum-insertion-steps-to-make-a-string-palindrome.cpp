class Solution {
public:
    int minInsertions(string s) {
        int sz = s.length();
        
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        
        for(int i = sz-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int t = i+1; t < sz; t++){
                dp[i][t] = (s[i] == s[t]) ? dp[i+1][t-1]+2 : max(dp[i+1][t], dp[i][t-1]);
            }
        }
        
        /*for(int i = 0; i < sz; i++){
            for(int t = 0; t < sz; t++)cout<< dp[i][t]<<" ";
            cout<< endl;
        }*/
        return sz-dp[0][sz-1];
    }
};