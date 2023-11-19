class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int ans = 0, x = nums[nums.size()-1],c = 0;
        
        for(int i = nums.size()-1; i >= 0;){
            if(nums[i] != x){
                ans++;
                i--;
                continue;
            }
            while(i >= 0 && nums[i] == x){
                //cout<<c<<endl;
                c++;
                i--;
            }
            if(i >= 0)ans += c;
            //if(c == nums.size())return 0;
            if(i >= 0)x = nums[i];
        }
        return ans;
    }
};