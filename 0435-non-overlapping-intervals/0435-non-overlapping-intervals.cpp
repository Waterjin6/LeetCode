bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
}
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0, b = 0, is = intervals.size();
        //sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), cmp);

        /*for(int i = 0; i < is; i++){
            cout<< intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }*/
        for(int i = 1; i < is; i++){
            if(intervals[i][0] < intervals[b][1])ans++;
            else b = i;
        }
        return ans;
    }
};