class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        
        int s = nums[0], cnt = 1, sum = 0;
        
        for(int i = 1; i<nums.size(); i++){
            if(s == nums[i]){
                if(cnt == 2){
                    nums[i] = INT_MAX;
                }
                else cnt++;
            }
            else {
                s = nums[i];
                sum += cnt;
                cnt = 1;
            }
            if(i == nums.size()-1)sum += cnt;
        }
        
        sort(nums.begin(),nums.end());
        return sum;
    }
};