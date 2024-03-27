class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, curr; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < k) ans++;
            curr = nums[i];
            for(int t = i+1; t < nums.size(); t++){
                curr *= nums[t];
                if(curr >= k)break;
                ans++;
            }
        }
        return ans;
    }
};