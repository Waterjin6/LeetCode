class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size()-1 && nums[i] < nums[i+1]; i++);
        //cout<< i<<endl;
        return nums[(i+1) % nums.size()];
    }
};