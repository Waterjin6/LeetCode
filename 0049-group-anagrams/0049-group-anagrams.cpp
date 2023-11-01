class Solution {
public:
    vector<vector<string>> group;
    
    int findIdx(string st){
        for(int i = 0; i < group.size(); i++){
            if(group[i][0] == st)return i;
        }
        return -1;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i = 0; i < strs.size(); i++){
            string st = strs[i];
            sort(st.begin(), st.end());
            
            int idx = findIdx(st);
            
            if(idx == -1){
                vector<string> v;
                v.push_back(st);
                v.push_back(strs[i]);
                group.push_back(v);
            }
            else{
                group[idx].push_back(strs[i]);
            }
        }
        
        for(int i = 0; i < group.size(); i++){
            group[i].erase(group[i].begin());
        }
        
        return group;
    }
};