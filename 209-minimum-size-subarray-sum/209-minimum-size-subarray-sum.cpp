class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int counter = target, start = 0, end = 0, maxLen = INT_MAX;
        
        while(end < nums.size()) {
            counter -= nums[end++];
            while(counter <= 0) {
                maxLen = min(maxLen, end - start);
                counter += nums[start++];
            }
        }
        return maxLen == INT_MAX ? 0 : maxLen;
    }
};