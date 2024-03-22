class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> nums(amount+1, 0);
        nums[0] = 1;
        
        for(int c : coins){
            for(int i = c; i <= amount; i++){
                nums[i] += nums[i-c];  
            }
        }
        
        return nums[amount];
    }
};