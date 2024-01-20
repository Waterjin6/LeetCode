class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ev;
        vector<int> od;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0)ev.push_back(nums[i]);
            else od.push_back(nums[i]);
        }
        
        for(int i = 0; i < od.size(); i++)ev.push_back(od[i]);
        return ev;
    }
};