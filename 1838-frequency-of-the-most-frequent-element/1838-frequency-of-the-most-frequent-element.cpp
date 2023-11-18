class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int mf = 0,scf, mcf, ck;
        
        for(int i = nums.size()-1; i >= 0 && i+1 > mf ;){
            scf = 0, mcf = 0;
            ck = k;
            int t = i;
            for(; t >= 0 && nums[i]== nums[t]; t--)scf++;

            //cout<<"first t : "<<t<<endl;
            ck = k;
            for(; t >= 0 && nums[t]+ck >= nums[i]; t--){
                mcf++;
                ck -= nums[i]-nums[t];
            }
            //cout<< "i : "<<i<<" t : "<< t<<endl;
            if(scf+mcf > mf) mf = scf+mcf;
            if(scf > 1)i -= scf;
            else i--;
        }
        return mf;    
    }
};