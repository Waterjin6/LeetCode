class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        
        vector<tuple<int,int,int>> st_ed_idx;
        vector<int> ans (sz, -1);
        
        for(int i = 0; i < sz; i++){
            st_ed_idx.push_back({intervals[i][0],intervals[i][1], i});
        }
        sort(st_ed_idx.begin(),st_ed_idx.end());
        
        for(int i = 0; i < sz; i++){
            for(int t = i; t < sz; t++){
                if(get<0>(st_ed_idx[t]) >= get<1>(st_ed_idx[i])){
                    ans[get<2>(st_ed_idx[i])] = get<2>(st_ed_idx[t]);
                    break;
                }
            }
        }
        return ans;
    }
};