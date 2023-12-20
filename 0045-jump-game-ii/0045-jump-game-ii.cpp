class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        vector<int> minJump (n, INT_MAX);
        
        minJump[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int t = 1; t <= nums[i]; t++){
                if(i+t >= n-1) return minJump[i]+1;
                minJump[i+t] = min(minJump[i+t], minJump[i]+1);
            }
        }
        return minJump[n-1];
    }
};