class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        vector<bool> dp(sl, false);
        dp[0] =true;
        
        for(int i = 0; i < sl; i++){
            for(int j = i+1; j <= sl; j++){
                if(dp[i]){
                    cout<< s.substr(i, j-i)<<endl;
                    if(find(wordDict.begin(),wordDict.end(), s.substr(i, j-i)) != wordDict.end())dp[j] = true;
                }
            }
        }
        return dp[sl];
    }
};