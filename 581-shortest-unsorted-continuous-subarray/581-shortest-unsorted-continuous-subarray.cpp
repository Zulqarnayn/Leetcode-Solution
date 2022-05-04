class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = -1, size = nums.size();
        int mx = nums[0], mn = nums[size - 1];
        
        for(int idx = 1; idx < size; idx++) {
            if(mx > nums[idx]) {
                end = idx;
            } else {
                mx = nums[idx];
            }
        }
        
        for(int idx = size - 2; idx >= 0; idx--) {
            if(mn < nums[idx]) {
                start = idx;
            } else {
                mn = nums[idx];
            }
        }
        
        return end - start + 1;
    }
};