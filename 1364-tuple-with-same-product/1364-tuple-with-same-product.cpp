class Solution {
public:
    void getPossCom(vector<int>& nums, int s, int e, int c, int &ans, int &sz){
        if(s >= e) return;
        if(c == nums[s]*nums[e]) {
            ans+= 8;
            getPossCom(nums, s+1, e-1, c, ans, sz);
        }
        else if(c > nums[s]*nums[e]) getPossCom(nums, s+1, e, c, ans, sz);
        else getPossCom(nums, s, e-1, c, ans, sz);

        return;
    }

    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0, sz = nums.size(), c;

        for(int fs = 0; fs < sz-3; fs++){
            for(int fe = sz-1; fe-fs > 2; fe--){
                c = nums[fs] * nums[fe];

                getPossCom(nums, fs+1, fe-1, c,ans, sz);
            }
        }

        return ans;
    }
};