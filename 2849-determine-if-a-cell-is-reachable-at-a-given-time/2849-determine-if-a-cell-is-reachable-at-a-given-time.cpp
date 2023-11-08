class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx-fx), dy = abs(sy - fy), fast = (dx < dy) ? dx : dy;
        
        if(fast + dx-fast + dy - fast > t)return false;
        if((dx + dy == 0)&&(t == 1))return false;
        
        return true;
    }
};