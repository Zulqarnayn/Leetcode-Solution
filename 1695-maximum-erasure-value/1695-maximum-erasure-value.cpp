class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> valueToIdxMap;
        vector<int> cummulativeSum(nums.size(), 0);
        
        for(int idx = 0; idx < nums.size(); idx++) {
            cummulativeSum[idx] = idx == 0 ? nums[idx] : cummulativeSum[idx-1] + nums[idx];
        }
        
        int start = 0, maxValueToErase = 0;
        
        for(int idx = 0; idx < nums.size(); idx++) {
            if(valueToIdxMap.count(nums[idx])) {
                start = max(start, valueToIdxMap[nums[idx]] + 1);
            }
            
            valueToIdxMap[nums[idx]] = idx;
            int currentMaxToErase = start == 0 ? cummulativeSum[idx] : cummulativeSum[idx] - cummulativeSum[start-1];
            maxValueToErase = max(maxValueToErase, currentMaxToErase);
        }
        
        return maxValueToErase;
    }
};