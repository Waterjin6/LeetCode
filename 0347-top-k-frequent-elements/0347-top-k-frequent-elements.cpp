class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        sort(nums.begin(),nums.end());

        int b = nums[0], c = 1;
        for(int i = 1; i < nums.size(); i++){
            if(b == nums[i])c++;
            else {
                pq.push({c, b});
                b = nums[i];
                c = 1;
            }
        }
        pq.push({c,b});

        vector<int> ans;

        while(k-- > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};