class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0; // d 0 : N = U, 1 : E = R, 2 : S = D, 3 : W = L
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0,1,0,-1};
        
        for(char c : instructions){
            if(c == 'G'){
                x += dx[d];
                y += dy[d];
            }
            else if(c == 'L') d = (d + 3)%4;
            else if(c == 'R') d = (d+1)%4;
        }
        return (x== 0 && y == 0) || d != 0;
    }
};