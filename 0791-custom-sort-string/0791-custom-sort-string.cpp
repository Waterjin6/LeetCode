class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> priority(26, -1);
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> chars;
        string ans = "", notInclude = "";
        
        int idx = 0;
        
        for(char x : order)priority[x-'a'] = idx++;
        
        for(char x : s){
            if(priority[x-'a'] == -1) notInclude += x;
            else chars.push({priority[x-'a'], x});
        }
        
        while(!chars.empty()){
            ans += chars.top().second;
            chars.pop();
        }
        
        return ans + notInclude;
    }
};