class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currS = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] > maxSum) maxSum = nums[i];
            if(currS+nums[i] < currS)currS = max(0,currS+nums[i]);
            else{
                currS += nums[i];
                if(maxSum < currS)maxSum = currS;
            }
        }
        return maxSum;
    }
};