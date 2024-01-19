class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = 0;
        vector<pair<int,int>> prs;

        for(int i = 0; i < nums1.size(); i++)prs.push_back({nums2[i], nums1[i]}); 

        sort(prs.rbegin(),prs.rend());
        // 애초에 입력값 자체를 정렬을 해놓고 시작했어야했음. 안그러면 진정한 의미의 최댓값을 구하기 힘듦

        for(int i = 0; i < nums1.size(); i++){
            pq.push(prs[i].second);
            sum += prs[i].second;

            if(pq.size() == k+1) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = max(ans, sum * prs[i].first);
            // i번째 값이 계산에 안들어갈경우 (위에서 빠졌을 경우) -> 그 전값들은 어차피 한번 처리 된거라 prs i 곱해도 노상관(짜피 최댓값 이미 구했음)
            // i번째 값이 계산에 들어갈 경우 => 작은 수가 아닐경우 => 해당되기 때문에 prs i값 곱해줘야함
        }
        return ans;
    }
};