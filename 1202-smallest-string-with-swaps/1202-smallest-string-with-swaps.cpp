class UnionFind {
    vector<int> parent;
public:
    UnionFind(int sz): parent(sz) {
        for(int idx = 0; idx < sz; idx++) {
            parent[idx] = idx;
        }
    }
    
    int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        
        if(pX != pY) {
            parent[pY] = pX;
        }
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.size();
        UnionFind uf = UnionFind(size);
        
        for(int idx = 0; idx < pairs.size(); idx++) {
            int x = pairs[idx][0];
            int y = pairs[idx][1];
            uf.unionSet(x, y);
        }
        
        unordered_map<int, vector<int> > uMap;
        
        for(int idx = 0; idx < size; idx++) {
            uMap[uf.find(idx)].push_back(idx);
        }
        
        for(auto c: uMap) {
            string temp = "";
            for(auto x: c.second) temp += s[x];
            
            sort(temp.begin(), temp.end());
            
            int t = 0;
            for(auto x: c.second) {
                s[x] = temp[t++];
            }   
        }
        
        return s;
    }
};