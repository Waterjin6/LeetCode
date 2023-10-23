class Solution {
public:

    vector<int> findHeight(vector<int> height){
        
        sort(height.rbegin(), height.rend());
        
        return height;
    }
    
    
    int maxArea(vector<int>& height) {
        int ans = 0;
        
        vector<int> highs = findHeight(height);
        
        for(int i = 1; i < highs.size(); i++){
            int startPoint = 0, endPoint = height.size()-1;
            int currHigh = highs[i];
            
            for(; (startPoint < height.size())&&(height[startPoint] < currHigh); startPoint++);
            for(; (endPoint >= 0)&&(height[endPoint] < currHigh); endPoint--);
            
            if(startPoint >= endPoint)continue;
            
            int currAns = highs[i] * (endPoint - startPoint);
            if(currAns > ans)ans = currAns;
        }
        
        return ans;
    }
};