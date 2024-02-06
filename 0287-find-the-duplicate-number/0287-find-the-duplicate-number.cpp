class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> num;
        int ed = nums.size()-1;
        
        for(int i = 0; i <= ed; i++){
            if(num.find(nums[i]) != num.end())return nums[i];
            else num.insert(nums[i]);
        }
        
        return 0;
    }
};