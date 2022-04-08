//  Time Complexity: O(N⋅log(k)+M⋅log(k))
//  Space Complexity: O(k)
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> elements;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        
        for(auto num: nums) {
            elements.push(num);
        }
        
        while(elements.size() > k) elements.pop();
    }
    
    int add(int val) {
        elements.push(val);
        while(elements.size() > K) elements.pop();
        return elements.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */