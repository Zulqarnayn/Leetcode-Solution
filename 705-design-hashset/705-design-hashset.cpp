class MyHashSet {
    vector<bool> hashArr;
public:
    MyHashSet() {
        hashArr.resize(1000001, false);
    }
    
    void add(int key) {
        if (!hashArr[key]) hashArr[key] = true;
    }
    
    void remove(int key) {
        if (hashArr[key]) hashArr[key] = false;
    }
    
    bool contains(int key) {
        return hashArr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */