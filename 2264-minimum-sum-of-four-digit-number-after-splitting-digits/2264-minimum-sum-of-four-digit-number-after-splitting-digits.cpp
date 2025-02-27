class Solution {
public:
    int minimumSum(int num) {
        int ans = 0, t = 0;
        string s = to_string(num);

        priority_queue<int> pq;
        for(int i = 0; i < s.length(); i++) {
            pq.push(s[i]-'0');
        }

        while(!pq.empty()){
            ans += pq.top()*pow(10,t);
            pq.pop();
            if(pq.empty())break;
            ans += pq.top()*pow(10,t);
            pq.pop();
            t++;
        }
        return ans;
    }
};