class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0, st = 1;
        while(n-st >= 0){
            n -= st++;
            //cout<<n<<endl;
            ans++;
        }
        return ans;
    }
};