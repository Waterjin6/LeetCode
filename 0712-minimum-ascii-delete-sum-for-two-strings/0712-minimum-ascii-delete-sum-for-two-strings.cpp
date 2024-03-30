class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0;
        for(char c : s1)ans += c;
        for(char c : s2)ans += c;
        
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        
        for(int i = 0; i < s1.length(); i++){
            for(int t = 0; t < s2.length(); t++){
                if(s1[i] == s2[t]) dp[i+1][t+1] = max(dp[i][t]+s1[i], max(dp[i+1][t], dp[i][t+1]));
                else dp[i+1][t+1] = max(dp[i+1][t], dp[i][t+1]);
            }
        }
        
        return ans - 2*dp[s1.length()][s2.length()];
    }
};