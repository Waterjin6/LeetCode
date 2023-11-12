class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s = 0, e= 0;
        vector<string> ans;
        
        while(s < nums.size()){
            string str = to_string(nums[s]);
            for(int i = 0; e < nums.size() && nums[e] == nums[s]+i; i++)e++;
            if(s+1 < e){
                str += "->";
                str += to_string(nums[e-1]); 
            }
            ans.push_back(str);
            
            s = e;
        }
        
        return ans;
    }
};