class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // Full descriptions are given below
        // catch: keep an eye on k. if it is greater total size take reminder
        
        //v2:
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> resultArray(row, vector<int>(col));
        
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                //flatten 
                int newIndexInOneDArray = (idx * col + idy) + k;
                int i = (newIndexInOneDArray / col) % row;
                int j = newIndexInOneDArray % col;
                
                resultArray[i][j] = grid[idx][idy];
            }
        }
        
        return resultArray;
        /*v1:
        //n = row count, m = column count
        
        //0(n * m) memory
        int row = grid.size(), col = grid[0].size();
        vector<int> oneDArray(row*col);
        
        //O(n * m) time
        for(int idx = 0; idx < row; idx++) {
            for(int idy = 0; idy < col; idy++) {
                oneDArray[idx*col + idy] = grid[idx][idy];
            }
        }
        
        
        if(k > row * col) k %= (row * col);
        
        //O(n * m) time
        reverse(oneDArray.begin(), oneDArray.end());
        //O(k) time
        reverse(oneDArray.begin(), oneDArray.begin() + k);
        //O(n * m - k) time
        reverse(oneDArray.begin() + k, oneDArray.end());
        
        //O(n * m) time
        for(int idx = 0; idx < row * col; idx++) {
            int i = idx / col;
            int j = idx % col;
            grid[i][j] = oneDArray[idx];
        }
        
        return grid;
        
        /*
        TC = O(n * m)
        MC = O(n * m)
        
        Notes:
        ------
        2D matrix to 1D array
        ----------------------
        a(i,j) can be flatten to 1D array b(k)
        where k= i*m + j
        --> for i..row { for j..row { b[i*m+j] = a[i][j] } }

        To get back to 2D matrix from A(k)
        ----------------------------------
        i= k/m; //rounding down
        j = k -(i*m); or j= k %m (where modulus gives remainder)
        
        ------------------------------------------------------------------
        link: https://www.ce.jhu.edu/dalrymple/classes/602/Class12.pdf
        ------------------------------------------------------------------
        
        
        To reverse an array in O(1) space
        ---------------------------------
        1. Reverse the array.
        2. Reverse the subarray of the array consisting of first k elements.
        3. Reverse the rest of the array excluding the front subarray.
        ---------------------------------------------------------------------------------------------------
        https://medium.datadriveninvestor.com/array-rotation-o-1-space-solution-with-proof-of-correctness-c5af5713fe7c
        ---------------------------------------------------------------------------------------------------
        */
    }
};