class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int ans = 1, cur = 1;
        
        for(int i = 0; i < nums.size()-1;i++){
            if(nums[i]+1 == nums[i+1]){
                cur++;
                //cout<< nums[i]<<" "<<nums[i+1]<<" "<<cur<<endl;
                if(i == nums.size()-2) ans = max(ans, cur);
            }
            else{
                if(cur > ans) ans = cur;
                cur = 1;
            }
        }
        return ans;
    }
};