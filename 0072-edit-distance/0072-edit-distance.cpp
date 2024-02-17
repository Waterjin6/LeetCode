class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        
        for(int i = 1; i <= l1; i++) dp[i][0] = i;
        for(int i = 1; i <= l2; i++) dp[0][i] = i;
        
        for(int i = 1; i <= l1; i++){
            //cout<< "t : ";
            for(int t = 1; t <= l2; t++){
                if(word1[i-1] == word2[t-1]) dp[i][t] = dp[i-1][t-1];
                else dp[i][t] = min(dp[i-1][t], min(dp[i][t-1], dp[i-1][t-1]))+1;
                //cout<<t<<" ";
            }
            //cout<<endl;
            //cout<<"i : "<<i<<endl;
        }
        
        return dp[l1][l2];
    }
};