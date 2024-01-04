class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //sort(numbers.begin(), numbers.end());
        vector<int> ans = {2, 0};
        
        int st = 0, ed = numbers.size()-1, m;
        
        while(st < ed){
            m = numbers[st]+numbers[ed];
            if(m == target)break;
            if(m < target)st++;
            else ed--;
        }
        //cout<<st<<" "<<ed<<endl;
        ans[0] = st+1;
        ans[1] = ed+1;
        return ans;
    }
};