class Solution {
    int dp[201][201];
public:
    int calculateMinPath(int idx, int idy, vector<vector<int>>& triangle) {
        if(idx <0 || idx >= triangle.size() || idy < 0 || idy >= triangle[idx].size()) return 0;
        
        if(dp[idx][idy] != -1) return dp[idx][idy];
        
        int ret1 = 0, ret2 = 0;
        
        ret1 = triangle[idx][idy] + calculateMinPath(idx+1, idy, triangle);
        ret2 = triangle[idx][idy] + calculateMinPath(idx+1, idy + 1, triangle);
        
        return dp[idx][idy] = min(ret1, ret2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return calculateMinPath(0, 0, triangle);    
    }
};