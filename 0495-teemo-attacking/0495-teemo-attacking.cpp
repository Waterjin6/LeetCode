class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {   
        int ans = duration, sz = timeSeries.size(), lastPoizoned = timeSeries[0]+duration-1;
        
        for(int i = 1; i < sz; i++){
            /*if(lastPoizoned >= timeSeries[i]+duration-1){
                //cout<< "pass "<<endl;
                continue;
            }*/
            if(lastPoizoned >= timeSeries[i]){
                ans += timeSeries[i]+duration-1 -lastPoizoned;
                lastPoizoned = timeSeries[i] + duration -1;
                //cout<<" 2 : "<< ans<<endl;
                continue;
            }
            ans += duration;
            lastPoizoned = timeSeries[i] + duration -1;
            //cout<<ans<<endl;
        }
        
        return ans;
    }
};