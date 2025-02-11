class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, sz = nums.size(), range = sz/2, e = range-1, m=(s+e)/2;
        if(sz == 1)return nums[0];
        //cout<< " m : "<<m<<" , s : "<<s<<" , e : "<< e<<endl;

        while(s <= e){
            m = (s+e)/2;
            if (nums[2*m] == nums[2*m+1]) s = m+1;
            else e = m-1;
            //cout<< " m : "<<m<<" , s : "<<s<<" , e : "<< e<<endl;
        }
        //cout<< s;
        if(s == range)return nums[sz-1];
        return nums[2*s];
    }
};