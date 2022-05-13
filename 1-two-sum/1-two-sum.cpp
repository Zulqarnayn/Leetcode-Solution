class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Q1. is there duplicates
        
        // TC: - O(n)
        // SC: - O(n)
        unordered_map<int, int> uMap;
        
        for(int idx = 0; idx < nums.size(); idx++) {
            int remain = target - nums[idx];
            if(uMap.count(remain)) {
                return {idx, uMap[remain]};
            } else {
                uMap[nums[idx]] = idx;
            }
        }
        
        return {};
    }
};