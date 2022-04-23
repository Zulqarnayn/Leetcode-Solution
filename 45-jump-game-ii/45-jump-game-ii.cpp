class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> dp(size, 1e9);
        dp[size - 1] = 0;
        
        for(int idx = size - 2; idx >= 0; idx--) {
            for(int i = 1; i <= nums[idx]; i++) {
                int next_idx = idx + i >= size ? size - 1 : idx + i;
                dp[idx] = min(dp[idx], 1 + dp[next_idx]);
            }
        }
        
        return dp[0];
    }
};