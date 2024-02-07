class Solution {
public:
    int numTilings(int n) {
        if(n <= 2)return n;
        if(n == 3)return 5;
        
        vector<long> ans(n+1, 0);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 5;
        
        for(int i = 4; i <= n; i++) {
            ans[i] = (2*ans[i-1]+ ans[i-3])%1000000007;
            //cout<< ans[i]<<endl;
        }
        
        return ans[n];
    }
};