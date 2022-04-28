class Solution {
public:
    
    bool minimumEffort(int idx, int idy, vector<vector<int>>& heights, vector<vector<bool>>& visited, int threshold) {
        int row = heights.size();
        int col = heights[0].size();
        
        if(idx == row - 1 && idy == col - 1) return true;
        
        bool res = false;
        int dx[] = {0, 0, -1, +1};
        int dy[] = {-1, +1, 0, 0};
        
        
        for(int step = 0; step < 4; step++) {
            int newX = idx + dx[step];
            int newY = idy + dy[step];
            visited[idx][idy] = true;
            
            bool isNewRowValid = newX >= 0 && newX < row;
            bool isNewColValid = newY >= 0 && newY < col;
            
            if(isNewRowValid && isNewColValid && !visited[newX][newY]) {
                int diff = abs(heights[idx][idy] - heights[newX][newY]);
                if(diff <= threshold) {
                    res |= minimumEffort(newX, newY, heights, visited, threshold);
                }
            }
        }
        
        return res;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        int lo = 0, hi = 1000000;
        
        while(lo < hi) {
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            int mid = lo + (hi - lo) / 2;
            if(minimumEffort(0, 0, heights, visited, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};