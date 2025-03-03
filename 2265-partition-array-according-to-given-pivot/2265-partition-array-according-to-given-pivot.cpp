class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        int eq = 0, sz = nums.size();
        vector<int> more;

        for(int i = 0; i < sz; i++){
            if(nums[i] < pivot) less.push_back(nums[i]);
            else if(nums[i] == pivot) eq++;
            else more.push_back(nums[i]);
        }

        while(eq-- > 0) less.push_back(pivot);
        for(int i = 0; i < more.size(); i++) less.push_back(more[i]);
        return less;
    }
};