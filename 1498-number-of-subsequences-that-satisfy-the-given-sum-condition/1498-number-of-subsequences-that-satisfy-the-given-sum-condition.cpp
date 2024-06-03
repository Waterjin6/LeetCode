class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int sz = nums.size(), st = 0, ed = sz-1, m, b, e, mod = (int)1e9^7;
        unsigned long long ans = 0, x;
        vector<int> pw(sz+1,1);
        
        for(int i = 1; i <= sz; i++) pw[i] = (2*pw[i-1])%mod;
        
        sort(nums.begin(),nums.end());
        
        for(int st = 0; st < sz && 2*nums[st] <= target; st++){
            b = st;
            e = sz-1;
            while(b <= e){
                m = (b+e)/2;
                
                if(nums[m] > target-nums[st]) e = m-1;
                else b = m+1;
            }

            ans = (ans+ pw[e-st])%mod;
        }
        return ans;
        
    }
};