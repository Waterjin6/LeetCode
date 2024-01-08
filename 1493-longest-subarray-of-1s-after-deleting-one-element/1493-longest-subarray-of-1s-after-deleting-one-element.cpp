class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ones;
        int o = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)o++;
            else{
                if(o > 0)ones.push_back(o);
                ones.push_back(0);
                o = 0;
            }
        }
        if(o > 0)ones.push_back(o);
        
        if(ones.size() == 1){                                             
            if(ones[0] == 0)return 0;
            else return ones[0]-1;
        }
        if(ones.size() == 2){
            return ones[0]+ones[1];
        }
        for(int i = 0; i < ones.size()-2; i++){
            ans = max(ans, ones[i]+ones[i+1]+ones[i+2]);
        }
        return ans;
    }
};