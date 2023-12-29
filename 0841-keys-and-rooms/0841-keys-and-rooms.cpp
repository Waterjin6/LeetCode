class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> isVisited = {0};
        
        stack<int> st;
        st.push(0);
        
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            
            for(int i = 0; i < rooms[idx].size(); i++){
                if(isVisited.count(rooms[idx][i]) == 0){
                    isVisited.insert(rooms[idx][i]);
                    st.push(rooms[idx][i]);
                    if(rooms.size() == isVisited.size())return true;
                }
            }
        }

        return rooms.size() == isVisited.size();
        
    }
};
