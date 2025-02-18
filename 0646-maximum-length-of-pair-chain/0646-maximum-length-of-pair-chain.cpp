class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int sz = pairs.size(), ans = 1;

        vector<int> dp(sz,1);

        for(int i = 1; i < sz; i++){
            for(int t = i-1; t >= 0 && i-t > dp[i]-1; t--){
                if(pairs[t][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[t]+1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};