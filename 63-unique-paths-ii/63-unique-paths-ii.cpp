/*
Time Complexity - O(n*m)
Space Complexity - O(1)


Keep in mind:
 - first and last cell can have obstacle
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                if(obstacleGrid[idx][idy] == 1) {
                    if(idx == 0 && idy == 0) return 0;
                    if(idx == row - 1 && idy == col - 1) return 0;
                    obstacleGrid[idx][idy] = -1;
                }
            }
        }
        
        obstacleGrid[0][0] = 1;
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                if(obstacleGrid[idx][idy] == -1) {
                    obstacleGrid[idx][idy] = 0;
                    continue;
                } 
                
                if(idx-1 >= 0) {
                    obstacleGrid[idx][idy] += obstacleGrid[idx - 1][idy];
                }
                
                if(idy - 1 >= 0) {
                    obstacleGrid[idx][idy] += obstacleGrid[idx][idy - 1];
                }
            }
        }
        
        return obstacleGrid[row-1][col-1];
    }
};