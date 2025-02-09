class SnapshotArray {
public:
    map<int, map<int, int>> snapList; // index, snapID, val
    int snapID;

    SnapshotArray(int length) {
        snapID = -1;
    }
    
    void set(int index, int val) {
        snapList[index][snapID] = val;
        return;
    }
    
    int snap() {
        snapID++;
        return snapID;
    }
    
    int get(int index, int snap_id) {
        if(snapList.find(index) == snapList.end()) return 0;
        auto it = snapList[index].lower_bound(snap_id);
        if (it == snapList[index].begin()) return 0; 
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */