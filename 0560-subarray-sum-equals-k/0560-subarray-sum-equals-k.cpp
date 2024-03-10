class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        
        int s = 0, ans = 0;
        
        for(int x : nums){
            s += x;
            if(m[s-k] > 0) ans += m[s-k];
            m[s]++;
        }
        return ans;  
    }
};