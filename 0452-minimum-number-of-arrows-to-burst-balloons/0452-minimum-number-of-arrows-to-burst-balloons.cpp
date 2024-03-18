class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0, idx = 0;

        sort(points.begin(), points.end(), cmp);
        
        for(int i = 0; i < points.size(); i++){
            if(points[idx][1] < points[i][0] ){
                ans++;
                idx = i;
            }
        }
        ans++;
        return ans;
    }
};