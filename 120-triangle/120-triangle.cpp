class Solution {
    
public:
    int calculateMinPath(int idx, int idy, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(idx >= triangle.size() || idy >= triangle[idx].size()) return 0;
        if(dp[idx][idy] != -1) return dp[idx][idy];
        
        int ret1 = 0, ret2 = 0;
        
        ret1 = triangle[idx][idy] + calculateMinPath(idx+1, idy, triangle, dp);
        ret2 = triangle[idx][idy] + calculateMinPath(idx+1, idy + 1, triangle, dp);
        
        return dp[idx][idy] = min(ret1, ret2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return calculateMinPath(0, 0, triangle, dp);    
    }
};