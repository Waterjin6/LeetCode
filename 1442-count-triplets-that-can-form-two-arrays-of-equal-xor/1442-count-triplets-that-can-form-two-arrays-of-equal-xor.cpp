class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int sz = arr.size(), ans = 0, c;
        
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        
        for(int i = 0; i < sz; i++) dp[i][i] = arr[i];
        
        for(int i = 0; i < sz; i++){
            for(int t = i+1; t < sz; t++) dp[i][t] = dp[i][t-1]^ arr[t];
        }
        
        for(int i = 0; i < sz-1; i++){
            for(int t = i; t < sz; t++){
                c = dp[i][t];
                
                for(int a = t+1; a < sz; a++){
                    if(c == dp[t+1][a]) {
                        //cout<< i <<" "<<t+1<<" "<<a<<endl;
                        ans++;
                    }
                }
                
            }
        }
        /*for(int i = 0; i < sz; i++){
            for(int t = 0; t < sz; t++)cout<<dp[i][t]<<" ";
            cout<<endl;
        }*/
        return ans;
    }
};