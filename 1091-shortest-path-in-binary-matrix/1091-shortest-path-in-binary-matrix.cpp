typedef pair<int, int> pii;
class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid.size();
        
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;
        
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        queue<pii> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty()) {
            int cX = q.front().first;
            int cY = q.front().second;

            if(cX == row - 1 && cY == col - 1) {
                return grid[cX][cY];
            }

            for(auto direction : directions) {
                int nX = cX + direction[0];
                int nY = cY + direction[1];

                if(nX >= 0 && nX < grid.size() && nY >= 0 && nY < grid.size() && grid[nX][nY] == 0) {
                    q.push({nX, nY});
                    grid[nX][nY] = grid[cX][cY] + 1;
                }

            }
            q.pop();
        }
        
        return -1;
    }
};

/*
[[0, 1, 1, 1, 1], [0, 1, 1, 0, 0], [0, 1, 0, 1, 0], [1, 0, 1, 1, 0], [0, 0 , 1, 0, 0]]
[[0,1],[1,0]]
[[0,0,0],[1,1,0],[1,1,0]]
[[0,1,1,0,0,0],[0,1,0,1,1,0],[0,1,1,0,1,0],[0,0,0,1,1,0],[1,1,1,1,1,0],[1,1,1,1,1,0]]
*/