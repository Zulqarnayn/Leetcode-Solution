class Solution {
    int dx[4] = {0, 0, +1, -1};
    int dy[4] = {+1, -1, 0, 0};
public:
    
    void dfs(int x, int y, vector<vector<int>>& grid, int& sum) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) return;
        
        grid[x][y] = 0;
        sum++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny, grid, sum);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int result = 0;
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                if(grid[idx][idy] == 1) {
                    int sum = 0;
                    dfs(idx, idy, grid, sum);
                    result = max(result, sum);
                }
            }
        }
        
        return result;
    }
};