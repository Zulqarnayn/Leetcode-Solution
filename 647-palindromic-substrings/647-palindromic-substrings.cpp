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
        for(int i = 0; i < sz; i++) {
            for(int j = i; j < sz; j++) {
                cnt += memoization(s, i, j);
            }
        }
        
        return cnt;
    }
};

/*
"aaabbbcccabc"
*/