typedef pair<int, int> pii;

class Solution {
    int dx[4] = {0, 0, +1, -1};
    int dy[4] = {+1, -1, 0, 0};
public:
    int findIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        queue<pair<int, int>> q;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                if(dp[idx][idy] == 0) {
                    q.push({idx, idy});
                }
            }
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [x, y] = q.front(); q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] > matrix[x][y]) {
                        dp[nx][ny]--;
                        if(dp[nx][ny] == 0) {
                            q.push({nx, ny});
                        }
                        
                    }
                }
            }
            
            count++;
        }
        
        return count;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(row, vector<int> (col, 0));
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                for(int k = 0; k < 4; k++) {
                    int nx = idx + dx[k];
                    int ny = idy + dy[k]; 
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] > matrix[idx][idy]) {
                        dp[nx][ny]++;
                    }
                }
            }
        }
        
        return findIncreasingPath(matrix, dp);
    }
};