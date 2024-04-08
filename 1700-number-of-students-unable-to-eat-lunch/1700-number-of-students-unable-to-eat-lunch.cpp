class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sand[2] = {0,0};
        
        for(int x : students) sand[x]++;
        for(int x : sandwiches){
            if(sand[x] == 0)return sand[0]+sand[1];
            else sand[x]--;
        }
        return sand[0]+sand[1];
    }
};