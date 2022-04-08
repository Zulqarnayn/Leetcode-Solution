class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> elements;
        int size = matrix.size();
        
        for(int idx = 0; idx < size; idx++) {
            for(int idy = 0; idy < size; idy++) {
                elements.push(matrix[idx][idy]);
            }
        }
        
        while(elements.size() > k) {
            elements.pop();
        }
        
        return elements.top();
    }
};

/*
[[1,5,9],
[10,11,13],
[12,13,15]]
8
[[1,5,9],
[10,11,13],
[12,13,15]]
1
[[1,5,9],
[10,11,13],
[12,13,15]]
3
*/