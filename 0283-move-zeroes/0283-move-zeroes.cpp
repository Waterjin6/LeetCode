class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size();){
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
                cnt++;
            }
            else i++;
        }
        
        for(int i = 0; i < cnt; i++){
            nums.push_back(0);
        }
        return;
    }
};