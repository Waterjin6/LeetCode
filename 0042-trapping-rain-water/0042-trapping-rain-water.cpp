class Solution {
public:
    int trap(vector<int>& height) {
        int hs = height.size(), ans = 0, m;
        vector<int> lw(hs, 0);
        vector<int> rw(hs, 0);
        
        lw[0] = height[0];
        rw[hs-1] = height[hs-1];
        
        for(int i = 1; i < hs; i++) lw[i] = max(height[i], lw[i-1]);
        for(int i = hs-2; i >= 0; i--) rw[i] = max(height[i], rw[i+1]);
        
        for(int i = 0; i < hs; i++){
            m = min(lw[i],rw[i]);
            //cout<< m<<" "<<height[i]<<endl;
            if(m > height[i]) {
                //cout<< m<<endl;
                ans += m-height[i];
            }
        }
        return ans;
    }
};