class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(10001); // dp[k] = min Coin Num when n = k
        
        dp[0] = 0;
        
        for(int x = 1; x <= n; x++){
            dp[x] = x;
            for(int t = 1; t*t <= x; t++){
                dp[x] = min(dp[x], dp[x%(t*t)] + x/(t*t));
            }
            //cout<< x<<" "<< dp[x]<<endl;
        }
        
        return dp[n];
    }
};