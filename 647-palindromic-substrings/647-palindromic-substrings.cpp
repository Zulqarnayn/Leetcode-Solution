class Solution {
public:
    /*
    TC: O(n^3)
    
    bool isPalindrome(string s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        int cnt = 0;
        for(int idx = 0; idx < s.size(); idx++) {
            for(int idy = idx; idy < s.size(); idy++) {
                cnt += isPalindrome(s, idx, idy);
            }
        }
        
        return cnt;
    }
    */
    
    vector<vector<int>> dp;
    
    int memoization(string &s, int i, int j) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int cnt = 0;
        
        if(s[i] != s[j]) cnt = 0;
        else cnt = memoization(s, i + 1, j - 1);
        
        return dp[i][j] = cnt;
    }
    
    int countSubstrings(string s) {
        int sz = s.size();
        dp.resize(sz, vector<int>(sz, -1));
        
        int cnt = 0;
        for(int i = sz - 1; i >= 0; i--) {
            for(int j = i; j < sz; j++) {
                // memoization technique
                // cnt += memoization(s, i, j);
                if(i == j) {
                    dp[i][j] = 1;
                } else if(i + 1 == j) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                }
                
                cnt += dp[i][j];
            }
        }
        
        return cnt;
    }
};

/*
"aaabbbcccabc"
*/