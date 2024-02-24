class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;
        
        int l1 = nums1.size(), l2 = nums2.size(), idx = 1;
        
        for(int i = 0; i < l2; i++) pq.push({-(nums1[0]+nums2[i]), {0, i}});
        
        int sum;
        vector<int> v;
        
        while(k-- > 0 && !pq.empty()){
            tie(sum,v) = pq.top();
            pq.pop();
            ans.push_back({nums1[v[0]],nums2[v[1]]});
            
            //cout<< "v : "<<v[0]<<" "<<v[1]<<endl;
            if(v[0] < l1-1){
                //cout<<"push : "<<v[0]+1<<" "<<v[1]<<endl;
                pq.push({-(nums1[v[0]+1] + nums2[v[1]]), {v[0]+1, v[1]}});
            }
            //cout<< "top : "<< pq.top().second[0]<<" "<< pq.top().second[1]<<endl;
            //ans.push_back({nums1[pq.top().second[0]],nums2[pq.top().second[1]]});
            //pq.pop();
        }
        
        return ans;
    }
};