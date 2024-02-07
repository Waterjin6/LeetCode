class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        priority_queue<pair<int, char>> pq;
        
        // count frequency
        for(int i = 0; i < s.length(); i++) cnt[s[i]]++;
        
        // insert to queue
        for(auto i = cnt.begin(); i != cnt.end(); i++) pq.push({i->second, i->first});    
        
        // make ans
        string ans = "";
        while(!pq.empty()){
            for(int i = 0; i < pq.top().first; i++)ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};