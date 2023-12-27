class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, cSz = colors.length(), bef = 0;
        
        for(int i = 1; i < cSz; i++){
            if(colors[i] == colors[bef]){
                if(neededTime[i] < neededTime[bef]){
                    ans += neededTime[i];
                }
                else {
                    ans += neededTime[bef];
                    bef = i;
                }
            }
            else bef = i;
        }
        return ans;
    }
};