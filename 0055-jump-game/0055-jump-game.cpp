class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxI = 0;
        
        for(int i = 0; i < nums.size()-1; i++){
            if((i <= maxI)&&(i+nums[i] > maxI))maxI = i+nums[i];
        }
        
        return (maxI >= nums.size()-1) ? true : false;
    }
};