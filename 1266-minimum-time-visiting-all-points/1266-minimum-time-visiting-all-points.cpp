class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, dx, dy, d;
        for(int i = 0; i < points.size()-1; i++){
            dx = abs(points[i][0]-points[i+1][0]);
            dy = abs(points[i][1]-points[i+1][1]);
            d = (dx < dy) ? dx : dy;
            ans += d;
            dx -= d;
            dy -= d;
            ans += dx + dy;
        }
        return ans;
    }
};