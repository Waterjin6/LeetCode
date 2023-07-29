class Solution {
public:
    int op[4][2] = {{100,0},{75, 25}, {50,50}, {25, 75}};
    map<string, double> m;
    
    double poss(int sa, int sb) {
        if((sa <= 0)&&(sb <= 0))return 0.5;
        if (sa <= 0)return 1;
        if (sb <= 0)return 0;
        if (m.find(to_string(sa)+"-"+to_string(sb)) != m.end())
            return m[to_string(sa)+"-"+to_string(sb)];
        
        double pos;
        string st = to_string(sa)+"-"+to_string(sb);
        
        pos = 0.25*(poss(sa-op[0][0],sb-op[0][1]) + poss(sa-op[1][0],sb-op[1][1]) + poss(sa-op[2][0],sb-op[2][1]) + poss(sa-op[3][0],sb-op[3][1]));
        m.insert({st, pos});

        return pos;
    }
    
    double soupServings(int n) {
        if(n >= 5000) //I hate this part.
            return 1.0;
        
        return poss(n,n);
    }
};