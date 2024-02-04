class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0; 
        int f = 0, b = costs.size()-1, cs = costs.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> front;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> back;
        vector<bool> hired(cs, false);
        
        for(int i = 0; i < candidates; i++){
            front.push({costs[f], f++});
            back.push({costs[b], b--});
        }
        
        while(k-- > 0){
            while(!front.empty() && hired[front.top().second]) front.pop();
            while(!back.empty() && hired[back.top().second]) back.pop();
            
            while(front.size() < candidates && f < cs && hired[f] == false)front.push({costs[f],f++});
            while(back.size() < candidates && b >= 0 && hired[b] == false)back.push({costs[b],b--});
            
            if(front.size() == 0 || back.top().first < front.top().first){
                ans += back.top().first;
                hired[back.top().second] = true;
                back.pop();
            }
            else{
                ans += front.top().first;
                hired[front.top().second] = true;
                front.pop();
            }
        }
        
        return ans;
    }
};