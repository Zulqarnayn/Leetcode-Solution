class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int size = nums.size(), start = 0, end = size - 1, count = 0;
        
        while(start < end) {
            int sum = nums[start] + nums[end];
            
            if(sum > k) {
                end--;
            } else if(sum < k) {
                start++;
            } else {
                count++;
                start++;
                end--;
            }
        }
        
        return count;
    }
};