class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int is = intervals.size();
        
        if(is == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int s = 0, e = is-1;
        while(s <= e && intervals[s][1] < newInterval[0])s++;
        if(s >= is){
            intervals.push_back(newInterval);
            return intervals;
        }
         //cout<< s <<" "<<e<<endl;
        while(s <= e && intervals[e][0] > newInterval[1])e--;
        if(e < 0){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        //cout<< s <<" "<<e<<endl;
        newInterval[0] = min(intervals[s][0], newInterval[0]);
        newInterval[1] = max(intervals[e][1], newInterval[1]);
        //cout<< "new : "<< newInterval[0] <<" "<<newInterval[1]<<endl;
        
        intervals.erase(intervals.begin()+s, intervals.begin()+e+1);
        intervals.insert(intervals.begin()+s, newInterval);
        return intervals;
    }
};