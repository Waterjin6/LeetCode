class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> a(nums.end()-k, nums.end());
        vector<int> b(nums.begin(),nums.end()-k);
        nums = a;
        nums.insert(nums.end(), b.begin(),b.end());
        return;
    }
};