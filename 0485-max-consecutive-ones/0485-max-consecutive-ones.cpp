class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, l0 = -1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) ans = max(ans, i-l0);
            else l0 = i;
        }
        return ans;
    }
};