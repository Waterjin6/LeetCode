class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0, s = 0, e = nums.size()-1;
        sort(nums.begin(),nums.end());
        
        //cout<< nums[s]<<" "<<nums[e]<<endl;
        
        while(s < e && s >= 0 && e < nums.size()){
            if(nums[s]+nums[e] < k)s++;
            else if(nums[s]+nums[e] > k)e--;
            else if(nums[s]+nums[e] == k){
                cnt++;
                s++;
                e--;
                //cout<< s<<" "<<e<<endl;
            }
            //cout<< nums[s]<<" "<<nums[e]<<endl;
        }
        return cnt;
    }
};