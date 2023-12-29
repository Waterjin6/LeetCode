class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> isVisited(rooms.size(), false);
        
        stack<int> st;
        st.push(0);
        
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            isVisited[idx] = true;
            
            for(int i = 0; i < rooms[idx].size(); i++){
                if(isVisited[rooms[idx][i]] == false){
                    st.push(rooms[idx][i]);
                }
            }
        }
        for(int i = 0; i < rooms.size(); i++){
            if(isVisited[i] == false)return false;
        }
        return true;
        
    }
};