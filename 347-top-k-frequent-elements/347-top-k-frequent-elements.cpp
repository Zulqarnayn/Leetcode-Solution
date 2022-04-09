class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        
        for(auto num: nums) {
            countMap[num]++;
        }
        
        auto comp = [&countMap](int n1, int n2) { return countMap[n1] > countMap[n2]; };
        
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        
        for(auto p: countMap) {
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }
        
        vector<int> top(k);
        
        for(int idx = k - 1; idx >= 0; idx--) {
            top[idx] = heap.top();
            heap.pop();
        }
        
        return top;
    }
};