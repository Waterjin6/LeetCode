class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, sz = tickets.size();
        
        while(tickets[k] > 0){
            for(int i = 0; i < sz; i++){
                if(tickets[i] > 0){
                    ans++;
                    tickets[i]--;
                }
                if(i == k && tickets[i] == 0)break;
            }
        }
        return ans;
    }
};