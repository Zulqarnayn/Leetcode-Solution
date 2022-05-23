class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    void fill(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '.';
        
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'X') {
                fill(nx, ny, board);
            }
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for(int idx = 0; idx < board.size(); idx++) {
            for(int idy = 0; idy < board[0].size(); idy++) {
                if(board[idx][idy] == 'X') {
                    fill(idx, idy, board);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};