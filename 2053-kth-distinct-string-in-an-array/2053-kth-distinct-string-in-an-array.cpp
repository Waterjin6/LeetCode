class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> str_cnt;
        priority_queue<pair<int,string>> idx_str;
        
        for(string s : arr) str_cnt[s]++;
        
        for(int i = 0; i < arr.size(); i++){
            if(str_cnt[arr[i]] == 1)idx_str.push({-i, arr[i]});
        }
        if(k > idx_str.size())return {};
        while(--k > 0){
            //if(idx_str.empty())return {};
            idx_str.pop();
        }
        //if(idx_str.empty())return {};
        return idx_str.top().second;
        
    }
};