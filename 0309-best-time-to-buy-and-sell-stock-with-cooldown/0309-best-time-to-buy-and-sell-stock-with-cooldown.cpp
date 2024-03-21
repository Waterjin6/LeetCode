class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        
        vector<int> buy(sz, INT_MIN);
        vector<int> sell(sz, 0);
        vector<int> cooldown(sz, 0);
        
        buy[0] = -prices[0];
        
        for(int i = 1; i < sz; i++){
            buy[i] = max(buy[i-1], cooldown[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i]+prices[i]);
            cooldown[i] = max(sell[i-1], buy[i-1]);
        }
        
        return max(buy[sz-1],sell[sz-1]);
    }
};