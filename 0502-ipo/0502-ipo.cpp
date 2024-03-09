class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int sz = profits.size(), cnt = 0;
        vector<pair<int,int>> pairV;
        priority_queue<int> maxProfit;
        
        for(int i = 0; i < sz; i++){
            pairV.push_back({capital[i],profits[i]});
        }
    
        sort(pairV.begin(), pairV.end());
        
        while(k-- > 0){
            while(cnt < sz && pairV[cnt].first <= w){
                maxProfit.push(pairV[cnt].second);
                cnt++;
            }
            if(maxProfit.empty())return w;
            w += maxProfit.top();
            //cout<< w<<endl;
            maxProfit.pop();
        }
            
        return w;
    }
};