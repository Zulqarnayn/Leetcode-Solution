class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size(), total = sz * (sz + 1) / 2;
        for(auto num: nums) sum += num;
        return total - sum;
    }
};