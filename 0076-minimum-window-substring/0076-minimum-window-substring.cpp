class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> idxs;
        int cnt = 0;
        map<char, int> n;
        string ans = s;
        
        for(int i = 0; i < s.length(); i++){
            if(find(t.begin(),t.end(), s[i]) != t.end())idxs.push_back(i);
        }
        for(int i = 0; i < t.length(); i++)n[t[i]]++;
        
        map<char, int> c;
        int f = -1, b = 0;
        
        while(f <= b){
            for(; b < idxs.size() && cnt < t.length(); b++){
                if(c[s[idxs[b]]] < n[s[idxs[b]]])cnt++;
                c[s[idxs[b]]]++;
            }
            if(cnt < t.length())break;
            while(++f <= b && c[s[idxs[f]]] > n[s[idxs[f]]]){
                c[s[idxs[f]]]--;
            }
            //cout<< cnt<<endl;
            if(cnt == t.length() && ans.length() > idxs[b-1]-idxs[f]+1) ans = s.substr(idxs[f], idxs[b-1]-idxs[f]+1);
            //cout<< s.substr(idxs[f], idxs[b-1]-idxs[f]+1) <<endl;
            c[s[idxs[f]]]--;
            cnt--;

            //cout<< idxs[f]<<" "<<idxs[b-1]<<endl;
        }
        //cout<< f<<" "<<b<<endl;
        if(f == -1)return "";
        return ans;
    }
};