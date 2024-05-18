class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {   
        int ans = duration, sz = timeSeries.size(), lastPoizoned = timeSeries[0]+duration-1;
        
        for(int i = 1; i < sz; i++){
            if(lastPoizoned >= timeSeries[i]){
                ans += timeSeries[i]+duration-1 -lastPoizoned;
                lastPoizoned = timeSeries[i] + duration -1;
                continue;
            }
            ans += duration;
            lastPoizoned = timeSeries[i] + duration -1;
        }
        
        return ans;
    }
};