class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ns = nums.size(), ans = 0, f = 0, b = 0;
        queue<int> zIdx;
        
        for(; f < ns && b < ns; b++){
            if(nums[b] == 0){
                zIdx.push(b);
                if(k > 0){
                    k--;
                }
                else{
                    //cout<<"== : "<< f <<" "<< b-1 <<" , "<< k <<endl;
                    ans = max(ans, b-f);
                    f = zIdx.front()+1;
                    //cout<< f <<" "<< b <<" , "<< k <<endl;
                    //ans = max(ans, b-f+1);
                    zIdx.pop();
                }
                //ans = max(ans, b-f+1);
            }
            //cout<< f <<" "<< b <<" , "<< k <<endl;
        }
        
        return max(ans, b-f);
    }
};