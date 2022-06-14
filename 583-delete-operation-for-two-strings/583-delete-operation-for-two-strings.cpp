class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Size = word1.size();
        int w2Size = word2.size();
        
        vector<vector<int>> dp(w1Size + 1, vector<int>(w2Size + 1, 0));
        
        for(int idx = 1; idx <= w1Size; idx++) {
            for(int idy = 1; idy <= w2Size; idy++) {
                if(word1[idx-1] == word2[idy-1]) {
                    dp[idx][idy] = 1 + dp[idx-1][idy-1];
                } else {
                    dp[idx][idy] = max(dp[idx-1][idy], dp[idx][idy-1]);
                }
            }
        }
        
        return (w1Size + w2Size - 2 * dp[w1Size][w2Size]);
    }
};