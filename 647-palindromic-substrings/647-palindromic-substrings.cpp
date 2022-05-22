class Solution {
public:
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
};