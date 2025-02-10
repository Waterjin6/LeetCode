class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0, sz = citations.size(), e = sz-1, m;
        //while(s < sz && citations[s] == 0) s++;
        //if(s == sz)return 0;

        /*if(sz == 1){
            if(citations[0] > 0)return sz;
            return 0;
        }*/

        while(s <= e){
            m = (s + e)/2;

            if(citations[m] >= sz-m) e = m-1;
            else s = m+1;
        }
        //cout<< "s : "<< s << " , e : "<< e<<" , m : "<< m <<endl;
        //if(sz-s+1 > sz)return sz;
        return sz-s;
    }
};