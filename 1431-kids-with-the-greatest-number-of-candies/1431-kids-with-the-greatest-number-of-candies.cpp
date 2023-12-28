class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int bCandy = 0;
        vector<bool> ans;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] > bCandy) bCandy = candies[i];
        }
        
        for(int i = 0; i < candies.size(); i++){
            if(extraCandies+candies[i] >= bCandy)ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};