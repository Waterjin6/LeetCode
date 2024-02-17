class LRUCache {
public:
    int sz;
    list<pair<int,int>> li;
    unordered_map<int, list<pair<int,int>>::iterator> key_iter;
    
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        auto iter = key_iter.find(key);
        if(iter == key_iter.end())return -1;
        li.splice(li.begin(), li, iter->second);
        
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = key_iter.find(key);
        if(iter != key_iter.end()){
            li.splice(li.begin(), li, iter->second);
            iter->second->second = value;
        }
        else{
            if(li.size() == sz){
                key_iter.erase(li.back().first);
                li.pop_back();
            }
            li.push_front({key,value});
            key_iter[key] = li.begin();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */