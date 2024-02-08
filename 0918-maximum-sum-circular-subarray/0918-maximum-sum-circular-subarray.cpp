class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currSum = nums[0], currMax = nums[0], currMin = nums[0], finMax = nums[0], finMin = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            currMax = max(nums[i], currMax+nums[i]);
            finMax = max(finMax, currMax);
            currSum += nums[i];
            currMin = min(nums[i], currMin+nums[i]);
            finMin = min(finMin, currMin);
        }
        
        return (currSum == finMin) ? finMax : max(finMax, currSum - finMin);
    }
};