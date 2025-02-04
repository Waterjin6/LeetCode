class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, cSum = nums[0], s = 1, l = nums.size();

        while(s < l){
            if(nums[s-1] >= nums[s]){ // not ascending
                if(ans < cSum) ans = cSum;
                cSum = nums[s];
            }
            else{ // ascending
                cSum += nums[s];
            }
            s++;
        }

        if (cSum > ans) ans = cSum;
        return ans;
    }
};