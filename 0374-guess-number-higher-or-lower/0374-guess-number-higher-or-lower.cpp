/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st = 1, ed = n, m, res;
        while(st < ed){
            m = st/2 + ed/2;
            res = guess(m);
            if(res == 1)st = m+1;
            else if(res == -1)ed = m-1;
            else break;
        }
        if(st == ed)return st;
        return m;
    }
};