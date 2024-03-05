class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        
        vector<string> ans(score.size());
        
        if(pq.empty())return ans;
        ans[pq.top().second] = "Gold Medal";
        pq.pop();
        
        if(pq.empty())return ans;
        ans[pq.top().second] = "Silver Medal";
        pq.pop();
        
        if(pq.empty())return ans;
        ans[pq.top().second] = "Bronze Medal";
        pq.pop();
        int i = 4;
        
        while(!pq.empty()){
            ans[pq.top().second] = to_string(i++) ;
            pq.pop();
        }
        return ans;
    }
};