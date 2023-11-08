class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx-fx), dy = abs(sy - fy), fast = (dx < dy) ? dx : dy;
        int calc = fast + dx-fast + dy - fast;
        
        if(calc > t)return false;
        if((dx + dy == 0)&&(t == 1))return false;
        
        return true;
    }
};