class Bucket {
    vector<pair<int, int>> bucket;
    
    public:
    Bucket() {
        bucket = {};
    }
    
    int getValueFor(int key) {
        for(auto element: bucket) {
            if(element.first == key) {
                return element.second;
            }
        }
        
        return -1;
    }
    
    void update(int key, int value) {
        bool found = false;
        for(int idx = 0; idx < bucket.size(); idx++) {
            if(bucket[idx].first == key) {
                bucket[idx].second = value;
                found = true;
            }
        }
        
        if(!found) bucket.push_back({key, value});
    }
    
    void printA() {
        for(auto element: bucket) {
            cout <<"F: "<< element.first <<" S: " << element.second << endl;
        }
    }
    
    void remove(int key) {
        for(auto element: bucket) {
            if(element.first == key) {
                bucket.erase(std::remove(bucket.begin(), bucket.end(), element), bucket.end());
                break;
            }
        }
    }
};

class MyHashMap {
    vector<Bucket> bucketList;
    int keySpace;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keySpace = 2081;
        bucketList = {};
        
        for(int idx = 0; idx < keySpace; idx++) {
            bucketList.push_back(Bucket());
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int keyHash = key % keySpace;
        bucketList[keyHash].update(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int keyHash = key % keySpace;
        return bucketList[keyHash].getValueFor(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int keyHash = key % keySpace;
        bucketList[keyHash].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */