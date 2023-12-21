class RandomizedSet {
public:
    unordered_set<int> s;
    
    RandomizedSet() {
        ;
    }
    
    bool insert(int val) {
        if (s.count(val) == 1)return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.count(val) == 0)return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        auto iter = s.begin();
        int r = rand()%s.size();
        //int a = 0;
       // cout<< a<<" "<<r<<endl;
        //iter += r*sizeof(int);
        for(int i = 0; i < r; i++)iter++;

        return (*iter);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */