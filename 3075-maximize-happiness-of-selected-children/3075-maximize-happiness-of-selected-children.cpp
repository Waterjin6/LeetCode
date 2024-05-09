class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long minus = 0, ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        
        for(int i = 0; i < k && i < happiness.size(); i++){
            if(happiness[i]-minus <= 0)break;
            ans += happiness[i]-minus;
            minus++;
        }
        return ans;
    }
};