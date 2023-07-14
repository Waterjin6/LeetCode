class Solution {
public:
    void printV(vector<int>& v){
        cout << endl<< "vector : ";
        for(int i =0; i < v.size(); i++){
            cout <<v[i]<< " ";
        }
        return;
    }
    vector<int> plusOne(vector<int>& digits) {
        bool isDone = false;
        int i = digits.size()-1;
        
        while(isDone == false){
            cout << digits[i]<<"d"<< endl;
            if(digits[i] < 9){ // 0~9
                 cout <<"dddu"<< endl;
                digits[i]++;
                isDone = true;
            }
            else { // 9
                digits[i] = 0;
                
                if(i == 0){
                    digits.insert(digits.begin(),1);
                    isDone = true;
                }
                else{
                    cout << "chu";
                    i--;
                }
            }
            printV(digits);
        }
        return digits;
    }
};