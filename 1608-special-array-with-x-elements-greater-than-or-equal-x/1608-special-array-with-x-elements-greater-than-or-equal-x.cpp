class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size(), p = 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        
        for(int i = n-1; i >= 0; i--){
            m[nums[i]] = p+1;
            p++;
        }
        
        for(int x = nums[n-1]; x >= 0; x--){
            if(m[x] == 0) m[x] = m[x+1];
            //cout<< x<<" : "<< m[x]<<endl;
            if(m[x] == x)return x;
        }
        
        return -1; 
    }
};