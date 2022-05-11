class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numberCounter;
        // [1, 2, 3, 1] 
        // k
        // 1(0), 2(1), 3(2), 1(3 - 0) = 3 <= 3
        // [1, 2, 3, 1, 2, 3], k = 2
        // 1(0), 2(1), 3(2), 1(3), 2()
        for(int idx = 0; idx < nums.size(); idx++) {
            if(numberCounter.count(nums[idx])) {
                int diff = idx - numberCounter[nums[idx]];
                if(diff <= k) return true;
                numberCounter[nums[idx]] = idx;
            } else {
                numberCounter[nums[idx]] = idx;
            }
        }
        
        return false;
    }
};