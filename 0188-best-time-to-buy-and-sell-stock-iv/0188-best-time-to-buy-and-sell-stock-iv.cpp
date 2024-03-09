class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buyProfit(k, INT_MIN);
        vector<int> sellProfit(k, 0);
        
        for(int t = 0; t < prices.size(); t++){
            buyProfit[0] = max(buyProfit[0], -prices[t]);
            sellProfit[0] = max(sellProfit[0], buyProfit[0]+prices[t]);
            
            for(int i = 1; i < k; i++){
                buyProfit[i] = max(buyProfit[i], sellProfit[i-1]-prices[t]);
                sellProfit[i] = max(sellProfit[i], buyProfit[i]+prices[t]);
            }
        }
        
        return sellProfit[k-1];
    }
};