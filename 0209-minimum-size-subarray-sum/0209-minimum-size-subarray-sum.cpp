class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = nums[0], f = 0, b = 0;
        int ns = nums.size();
        
        while(f < ns && b < ns){
            //cout<<"1 : "<<b <<" "<< f <<endl;
            while(b < ns-1 && sum < target){
                sum += nums[++b];
            }
            //if(b == ns)break;

            //cout<<"sum : "<<sum<< " "<< b <<" "<< f <<endl;
            if(sum >= target)ans = min(ans, b-f+1);

            sum -= nums[f];
            f++;
        }
        //cout<< sum<<endl;
        if(ans == INT_MAX)return 0;
        return ans;
    }
};