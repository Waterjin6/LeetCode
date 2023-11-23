class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            vector<int> v(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(v.begin(), v.end());
            if(v.size() < 3)ans.push_back(true);
            else {
                int diff = v[0]-v[1];
                bool is = true;
                for(int i = 1; i < v.size()-1; i++){
                    if(v[i]-v[i+1] != diff){
                        is = false;
                        break;
                    }
                }
                ans.push_back(is);
            }
        }
        return ans;
    }
};