class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Hashing -> TC: O(n) --- O(n)
        // Sorting -> TC: O(nlogn) --- O(1) a1, a2, a3
        sort(nums.begin(), nums.end());
        
        for(int idx = 1; idx < nums.size(); idx++) {
            if(nums[idx-1] == nums[idx]) return true;
        }
        
        return false;
    }
};