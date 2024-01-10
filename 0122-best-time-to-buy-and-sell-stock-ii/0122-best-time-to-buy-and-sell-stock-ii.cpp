class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ps = prices.size(), b = prices[0], ans = 0;
        
        for(int i = 1; i < ps; i++){
            if(prices[i] >= b){
                ans += prices[i]-b;
            }
            b = prices[i];
        }
        
        return ans;
    }
};