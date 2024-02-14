class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> plus;
        queue<int> minus;
        
        for(int x : nums){
            if(x > 0) plus.push(x);
            else minus.push(x);
        }
        vector<int> ans;
        
        while(plus.size()&&minus.size()){
            ans.push_back(plus.front());
            ans.push_back(minus.front());
            plus.pop();
            minus.pop();
        }
        return ans;
    }
};