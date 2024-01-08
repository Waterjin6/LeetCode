class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int as = asteroids.size();
        bool c = false;
        
        for(int i = 0; i < as; i++){
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else{
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                else{
                    if(st.top() + asteroids[i] == 0) st.pop();
                    else {
                        c = false;
                        while(!st.empty() && st.top() > 0 && st.top()+asteroids[i] < 0){
                            c = true;
                            st.pop();
                        }
                        if(!st.empty() && st.top() + asteroids[i] == 0)st.pop();
                        else if(!st.empty() && st.top() + asteroids[i] > 0)continue;
                        else if(st.empty() || st.top() < 0 || c == true)st.push(asteroids[i]);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};