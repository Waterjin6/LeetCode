class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy1 = -prices[0], buy2 = -prices[0], sell1 = 0, sell2 = 0;
        
        for(int i = 1; i < prices.size(); i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(buy1+prices[i], sell1);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(buy2+prices[i], sell2);
            //cout<< buy1 <<" "<<sell1<<" "<<buy2<<" "<<sell2<<endl;
        }
        return sell2;
    }
};