class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int  sz = nums.size();
        vector<int> sum(10001, 0);
        vector<int> skip(10001, 0);
        vector<int> get(10001, 0);
        
        for(int x : nums) sum[x] += x;
        
        for(int i = 1; i < 10001; i++){
            skip[i] = max(skip[i-1], get[i-1]);
            get[i] = skip[i-1] + sum[i];
        }
        
        return max(skip[10000], get[10000]);
    }
};