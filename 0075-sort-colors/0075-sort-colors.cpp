class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0,0,0}, idx = 0;
        for(int i = 0; i < nums.size(); i++) c[nums[i]]++;
        
        for(int i = 0; i < 3; i++){
            while(c[i]-- > 0) nums[idx++] = i;
        }
        
        return;
    }
};