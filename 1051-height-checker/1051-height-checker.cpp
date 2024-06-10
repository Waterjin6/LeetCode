class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        
        for(int i = 0; i < heights.size(); i++){
            if(sorted[i] != heights[i])ans++;
            
        }
        return ans;
    }
};