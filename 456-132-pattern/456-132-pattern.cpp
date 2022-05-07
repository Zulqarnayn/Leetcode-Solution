class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minFoundsoFar = nums[0];
        stack<pair<int, int>> numStk;
        
        for(int idx = 1; idx < nums.size(); idx++) {
            while(numStk.size() && numStk.top().second <= nums[idx]) {
                numStk.pop();
            }
            
            if(numStk.size() && numStk.top().first < nums[idx]) return true;
            
            numStk.push({ minFoundsoFar, nums[idx] });
            minFoundsoFar = min(minFoundsoFar, nums[idx]);
        }
        
        return false;
    }
};