class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int f = 0, b = k-1;
        double ans = 0, sum = 0;
        
        for(int i = 0; i < k; i++) sum += nums[i];
        if(nums.size() == k)return sum/k;
        ans = sum;
        //cout<<ans/k<<endl;
        while(b < nums.size()-1){
            sum -= nums[f++];
            sum += nums[++b];
            //cout<<sum<<endl;
            ans = max(sum, ans);
        }
        //cout<<ans<<endl;
        return ans/k;
    }
};