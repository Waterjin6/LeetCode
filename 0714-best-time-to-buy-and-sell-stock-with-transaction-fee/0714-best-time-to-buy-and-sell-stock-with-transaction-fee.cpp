class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buyPF = INT_MIN, sellPF = 0;
        
        for(int x : prices){
            buyPF = max(buyPF, sellPF - x);
            sellPF = max(sellPF, buyPF + x - fee);
        }
        return sellPF;
    }
};