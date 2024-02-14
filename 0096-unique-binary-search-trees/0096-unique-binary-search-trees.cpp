class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int t = 0; t <= i-1; t++){
                //cout<<t<<" "<<i-1-t<<endl;
                dp[i] += dp[t]*dp[i-1-t];
            }
        }
        //for(int i = 1; i <= n; i++)cout<< dp[i]<<" ";
        //cout<< endl;
        return dp[n];
    }
};