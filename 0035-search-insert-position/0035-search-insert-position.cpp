class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        if(nums[0] > target) return 0;
        else if(nums[nums.size()-1] < target) return nums.size();
        
        else {
            for(i = 0; i < nums.size(); i++){
                if(nums[i] == target) return i;
                else if((i < nums.size()-1)&&(nums[i] <= target)&&(target < nums[i+1]))return i+1;
            }
        }

        return -5;
    }
};