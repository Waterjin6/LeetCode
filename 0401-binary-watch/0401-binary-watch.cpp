class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn >8) return {};
        vector<string> ans;
        string str;
        vector<vector<string>> hours(4);
        
        hours[0] = {"0"};
        hours[1] = {"1","2", "4","8"};
        hours[2] = {"3","5","6","9","10"};
        hours[3] = {"7","11"};
        
        vector<vector<string>> minutes(6);
        
        minutes[0] = {"00"};
        minutes[1] = {"01","02","04","08", "16", "32"};
        minutes[2] = {"03","05","06","09","10","12","17","18","20","24", "33","34","36", "40","48"};
        minutes[3] = {"07","11","13","14","19","21","22","25","26","28","35","37","38","41","42","44","49","50","52","56"};
        minutes[4] = {"15","23","27","29","30","39","43","45", "46", "51","53","54", "57","58"};
        minutes[5] = {"31","47","55","59"};
        
        for(int i = 0; i <= turnedOn && i <= 3; i++){
            if(turnedOn - i > 5)continue;
            for(int t = 0; t < hours[i].size(); t++){
                for(int a = 0; a < minutes[turnedOn-i].size(); a++){
                    ans.push_back(hours[i][t]+":"+minutes[turnedOn-i][a]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};