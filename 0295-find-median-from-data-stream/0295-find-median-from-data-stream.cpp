class MedianFinder {
public:
    priority_queue<int> f;
    priority_queue<int,vector<int>, greater<int>> s;
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(f.size() == 0 && s.size() == 0)f.push(num);
        else if(f.size() > s.size()){
            if(f.top() > num){
                s.push(f.top());
                f.pop();
                f.push(num);
            }
            else s.push(num);
        }
        else if(f.size() < s.size()){
            if(s.top() < num){
                f.push(s.top());
                s.pop();
                s.push(num);
            }
            else f.push(num);
        }
        else{
            if(s.top() >= num)f.push(num);
            else s.push(num);
        }
        //cout<< f.size()<<" "<<s.size()<<endl;
        return;
    }
    
    double findMedian() {
        if(f.size() == s.size())return double(f.top()+s.top())/2;
        if(f.size() > s.size())return f.top();
        return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */