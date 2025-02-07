class TimeMap {
public:
    map<string, map<int, string>*> mapP;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // key가 없으면 새로운 map을 동적 할당
        if (mapP.find(key) == mapP.end()) mapP[key] = new map<int, string>();
    
        // 포인터를 통해 insert() 호출
        mapP[key]->insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mapP.find(key) == mapP.end()) return ""; // 아예 값이 없음

        auto it = mapP[key]->upper_bound(timestamp); // 타임스탬프보다 큰값중에 가장 작은값
        if (it == mapP[key]->begin()) return ""; // timestamp 이하 값이 없음
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */