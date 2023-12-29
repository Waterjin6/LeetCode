class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int ls = 0, rs = 0;
        
        for(int i = 1; i < nums.size(); i++) rs += nums[i];

        for(int i = 0; i < nums.size(); i++){
            //cout<<i<<" : "<< ls <<" "<<rs<<endl;
            if(ls == rs) return i;
            ls += nums[i];
            if(i+1 < nums.size())rs -= nums[i+1];
        }
        return -1;
    }
};