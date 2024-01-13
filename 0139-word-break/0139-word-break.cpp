class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        vector<bool> dp (sl+1, 0);
        
        dp[0] = true;
        
        for(int i = 1; i <= sl; i++){
            for(int t = i-1; t >= 0; t--){
                if(dp[t] && find(wordDict.begin(), wordDict.end(),s.substr(t, i-t)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sl];
    }
};