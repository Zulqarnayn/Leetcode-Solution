class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /*
        0 - go right
        1 - go bottom
        2 - go left
        3 - go top
        */
        int dir = 0, i = 1, j = 1, val = 0;
        int left = 1, right = n, top = 1, bottom = n;
        vector<vector<int>> result(n, vector<int>(n));
        
        while(left <= right && top <= bottom) {
            ++val;
            result[i-1][j-1] = val;
            if(dir == 0) {
                if(j == right) {
                    dir = 1;
                    top += 1;
                    i = top;
                } else {
                    j++;
                }
            } else if(dir == 1) {
                if(i == bottom) {
                    dir = 2;
                    right -= 1;
                    j = right;
                } else {
                    i++;
                }
            } else if(dir == 2) {
                if(j == left) {
                    dir = 3;
                    bottom -= 1;
                    i = bottom;
                } else {
                    j--;
                }
            } else if(dir == 3) {
                if(i == top) {
                    dir = 0;
                    left += 1;
                    j = left;
                } else {
                    i--;
                }
            }
        }
        
        return result;
    }
};