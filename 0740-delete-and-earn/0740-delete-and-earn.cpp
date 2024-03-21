class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001, 0); // dp로 총합값 저장
        vector<int> get(10001, 0);
        
        for(int x : nums) sum[x] += x;
        
        get[1] = sum[1];
        
        for(int i = 2; i < 10001; i++){
            get[i] = max(get[i-1], get[i-2] + sum[i]);
        }
        
        return get[10000];
    }
};