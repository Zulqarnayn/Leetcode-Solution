class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        
        int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
        int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                
                int liveCount = 0;
                
                for(int k = 0; k < 8; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    
                    if(xx >= 0 && xx < row && yy >= 0 && yy < col) {
                        // cout <<" xx: " << xx <<" yy: " << yy << endl;
                        liveCount += board[xx][yy];
                    }
                }
                // cout <<"( " << i <<", " << j << " ) " << liveCount << endl;
                if(board[i][j] == 1) {
                    //first cond
                    if(liveCount < 2 || liveCount > 3) res[i][j] = 0;
                    else res[i][j] = 1;
                } else {
                    if(liveCount == 3) res[i][j] = 1;
                    else res[i][j] = 0;
                }
            }
        }
        board = res;
    }
};

/*
[
[0,1,0],
[0,0,1],
[1,1,1],
[0,0,0]
]


[
[0,0,0],
[0,0,1],
[0,1,1],
[0,0,0]
]

*/