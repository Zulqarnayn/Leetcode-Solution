class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> uMap;
        
        for(auto num: nums) {
            uMap[num] = true;
        }
        
        for(int idx = 1; ; idx++) {
            if(uMap.find(idx) == uMap.end()) return idx;
        }
    }
};