class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0, sz = citations.size(), e = sz-1, m;

        while(s <= e){
            m = (s + e)/2;
            if(citations[m] >= sz-m) e = m-1;
            else s = m+1;
        }

        return sz-s;
    }
};