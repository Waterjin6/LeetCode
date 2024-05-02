class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> exist;
        
        for(int x : nums){
            if(x > 0){
                if(exist.count(-x) && ans < x) ans = x;
            }
            else if(x < 0){
                if(exist.count(-x) && ans < -x) ans = -x;    
            }
            
            exist.insert(x);
        }
        if(ans == 0)return -1;
        return ans;
    }
};