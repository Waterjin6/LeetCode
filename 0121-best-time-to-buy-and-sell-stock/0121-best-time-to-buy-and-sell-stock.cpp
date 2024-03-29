class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 10001, s = -1;
        int ans = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(b > prices[i]){
                ans = max(ans, s-b);
                b = prices[i];
                s = prices[i];
            }
            if(s < prices[i]) s = prices[i];
        }
        
        return max(ans, s-b);
    }
};