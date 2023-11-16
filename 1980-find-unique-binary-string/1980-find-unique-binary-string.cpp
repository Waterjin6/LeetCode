class Solution {
public:
    void makeList(int cnt, int sz, string s, vector<string>& list){
        if(cnt == sz){
            list.push_back(s);
            return;
        }
        makeList(cnt+1, sz, s+'0', list);
        makeList(cnt+1, sz, s+'1', list);
        
        return;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> list;
        string s = "";
        makeList(0,nums.size(),s, list);
        
        for(int i = 0; i < list.size(); i++){
            if(find(nums.begin(),nums.end(),list[i]) == nums.end())return list[i];
        }
        
        return s;
    }
};