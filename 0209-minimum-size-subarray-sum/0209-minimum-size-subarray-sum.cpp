class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = nums[0], f = 0, b = 0;
        int ns = nums.size();
        
        while(f < ns && b < ns){
            while(b < ns-1 && sum < target) sum += nums[++b];
            if(sum >= target)ans = min(ans, b-f+1);
            sum -= nums[f];
            if(b == ns-1 && sum < target)break;
            f++;
        }

        if(ans == INT_MAX)return 0;
        return ans;
    }
};