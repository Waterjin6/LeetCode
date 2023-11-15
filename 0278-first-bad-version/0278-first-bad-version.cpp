// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long s = 1, e = n, m = (s+e)/2;
        while(s<e){
            m = (s+e)/2;
            if(isBadVersion(m)==true)e = m;
            else s = m+1;
        }
        return (s+e)/2;
    }
};