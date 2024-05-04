class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int st = 0, ed = people.size()-1, ans = 0;
        
        sort(people.begin(),people.end());

        while(ed > st && people[ed] > limit-people[st]){
            //cout<< "firs : "<<people[ed]<<" "<<limit-people[st] <<endl;
            ans++;
            ed--;
        }
        //cout<< "first : "<<ans<<endl;
        
        while(st <= ed){
            //cout<<st <<" "<<ed<<endl;
            while(st < ed && people[st]+people[ed] > limit){
                ans++;
                ed--;
            }
            if(st < ed && people[st]+people[ed] <= limit){
                ans++;
                st++;
                ed--;
            }
            else {
                ans++;
                st++;
            }
        }
        return ans;
    }
};