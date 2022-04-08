class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> elements;
        
        for(auto num: nums) {
            elements.push(num);
        }
        
        while(elements.size() > k) {
            elements.pop();
        }
        
        return elements.top();
    }
};