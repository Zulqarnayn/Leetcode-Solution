class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() == 1) return 0;
        
        sort(stockPrices.begin(), stockPrices.end());
        long long int lastDx = INT_MAX - 1, lastDy = INT_MAX - 1;
        int cnt = 0;
        
        for(int idx = 0; idx < stockPrices.size() - 1; idx++) {
            int dx = stockPrices[idx + 1][0] - stockPrices[idx][0];
            int dy = stockPrices[idx + 1][1] - stockPrices[idx][1];
            
            if(lastDx == INT_MAX - 1) {
                cnt++;
            } else if(lastDx * dy != lastDy * dx) {
                cnt++;
            }
            
            lastDx = dx;
            lastDy = dy;
        }
        
        
        return cnt;
    }
};
/*
[[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]

[[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1], [9,1]]
[[3,4],[1,2],[7,8],[2,3]]
[[6,3],[7,2],[8,2]]

[[1, 1], [2, 2], [3, 1], [4, 2], [5, 1], [6, 2]]


*/