class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cSz = citations.size();
        
        sort(citations.rbegin(),citations.rend());
        
        for(int i = cSz; i >= 1; i--){ // gap In 
            if(citations[i-1] >= i)return i;
        }
        
        return 0;
    }
};