class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int sz = arr.size();
        vector<bool> visited(sz, 0);
        stack<int> st;
        int c;

        st.push(start);

        while(!st.empty()){
            c = st.top();
            st.pop();
            
            if(visited[c] == true) continue;
            if(arr[c] == 0) return true;

            visited[c] = true;

            if(c+arr[c] < sz && visited[c+arr[c]] == false) st.push(c+arr[c]);
            if(c-arr[c] >= 0 && visited[c-arr[c]] == false) st.push(c-arr[c]);
        }

        return false;
    }
};