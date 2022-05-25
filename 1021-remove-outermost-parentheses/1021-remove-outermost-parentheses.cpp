class Solution {
public:
    string removeOuterParentheses(string s) {
        /*
        // First Approach
        // Time Complexity - O(N)
        // Space Complexity - O(N)
        stack<pair<char, int>> parenthesesStack;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(s[idx] == ')') {
                if(parenthesesStack.size() == 1) {
                    s[parenthesesStack.top().second] = '*';
                    s[idx] = '*';
                }
                
                parenthesesStack.pop();
            } else {
                parenthesesStack.push({'(', idx});
            }
        }
        
        string result = "";
        for(auto ch: s) {
            if(ch != '*') result += ch;
        }
        
        return result;
        */
        
        /*
        Second Approach
        */
        
        string result;
        int count = 0;
        
        for(auto c: s) {
            if(c == '(') {
                if(count++) {
                    result += "(";
                }
            } else {
                if(--count) {
                    result += ")";
                }
            }
        }
        
        return result;
    }
};