class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int changeIdx = nums.size()-1, changeIdx2 = nums.size()-1;
        while(changeIdx-1 >= 0 && nums[changeIdx-1] >= nums[changeIdx])changeIdx--;
        changeIdx--;
        if(changeIdx < 0){
            sort(nums.begin(), nums.end());
            return;
        }
        while(changeIdx2 >= 0 && nums[changeIdx2] <= nums[changeIdx])changeIdx2--;
        //cout<< changeIdx<<" "<<changeIdx2<<endl;
        swap(nums[changeIdx], nums[changeIdx2]);
        
       // cout<< changeIdx<<" "<<changeIdx2<<endl;
        
        sort(nums.begin()+changeIdx+1, nums.end());

        //sort(nums.begin(), nums.end());
        
        return;
    }
};