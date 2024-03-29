class Solution {
public:
    
    bool checkPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(checkPalindrome(s)) return 1;
        return 2;
    }
};