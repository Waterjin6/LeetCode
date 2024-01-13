class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        vector<bool> dp(sl, false);
        dp[0] =true;
        
        for(int i = 1; i <= sl; i++){
            for(int j = i+1; j <= sl+1; j++){
                if(dp[i-1] && find(wordDict.begin(),wordDict.end(), s.substr(i-1, j-i)) != wordDict.end())dp[j-1] = true;
            }
        }
        return dp[sl];
    }
};