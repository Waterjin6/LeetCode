class Solution {
public:
    int findIdx(vector<int>& nums){
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] >= 1)return i;
        }
        return -1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        
        int firstPlus = findIdx(nums);
        //cout<< firstPlus<<endl;
        if(firstPlus == -1)return 1;
        
        int n=1;
        //cout<< nums[firstPlus];
        while((firstPlus < nums.size())&&(n == nums[firstPlus])){
            firstPlus++;
            n++;
        }
        return n;
    }
};