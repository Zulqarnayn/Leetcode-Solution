class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int calculateZeroCount(string &s) {
        int zero = 0;
        for(const auto &c: s) {
            if(c == '0') zero++;
        }
        
        return zero;
    }
    
    int calculateMaxFor(int idx, vector<string>& strs, int m, int n) {
        if(idx >= strs.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        int zero = calculateZeroCount(strs[idx]);
        int one = strs[idx].size() - zero;
        
        int include = 0;
        if(zero <= m && one <= n) {
            include = 1 + calculateMaxFor(idx + 1, strs, m - zero, n - one);
        }
        int exclude = calculateMaxFor(idx + 1, strs, m, n);
        
        return dp[idx][m][n] = max(include, exclude);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return calculateMaxFor(0, strs, m, n);
    }
};

/*
["10","0001","111001","1","0"]
5
3
["10","0","1"]
1
1
*/