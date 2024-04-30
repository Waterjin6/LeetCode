class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans = {area, 1};
        
        for(int x = 1; x <= area/x; x++){
            if(area % x == 0 && area/x-x < ans[0]-ans[1]){
                ans[0] = area/x;
                ans[1] =x;
            }
            
        }
        return ans;
    }
};