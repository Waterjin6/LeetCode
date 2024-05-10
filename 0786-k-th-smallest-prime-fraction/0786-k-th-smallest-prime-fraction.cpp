class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<tuple<double,int,int>> pq;
        int sz = arr.size();

        for(int i = 0; i < sz; i++){
            for(int t = sz-1; t >= 0; t--){
                if(pq.size() < k)pq.push({double(arr[i])/double(arr[t]), arr[i], arr[t]});
                else {
                    if(get<0>(pq.top()) <= double(arr[i])/double(arr[t])) break;
                    pq.pop();
                    pq.push({double(arr[i])/double(arr[t]), arr[i], arr[t]});
                }
            }
        }
        return {get<1>(pq.top()),get<2>(pq.top())};
    }
};