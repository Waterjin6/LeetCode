class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true;
        int i = 0;
        for(; i < nums.size()-1 && nums[i] == nums[i+1]; i++);
        if(i == nums.size()-1)return true;
        if(nums[i] > nums[i+1]) increase = false;
        //cout<< increase<<endl;
        if(increase){
            for(; i < nums.size()-1; i++){
                if(nums[i] > nums[i+1])return false;
            }
        }
        else{
            for(; i < nums.size()-1; i++){
                if(nums[i] < nums[i+1])return false;
            }
        }
        return true;
    }
};