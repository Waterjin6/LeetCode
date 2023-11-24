class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans = 0, s = 0, e = piles.size()-1;
        while(s < e-1){
            ans += piles[e-1];
            s++;
            e -= 2;
        }
        return ans;
    }
};