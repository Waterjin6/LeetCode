class SmallestInfiniteSet {
public:
    set<int> s;
    
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++)s.insert(i);
        return;
    }
    
    int popSmallest() {
        int x = *(s.begin());
        //cout<<x<<endl;
        s.erase(s.begin());
        return x;
    }
    
    void addBack(int num) {
        s.insert(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */