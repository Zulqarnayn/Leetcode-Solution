class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indexes;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(s[idx] == '(') {
                indexes.push(idx);
            } else if(indexes.size()) {
                s[indexes.top()] = s[idx] = '.';
                indexes.pop();
            }
        }
        
        int result = 0, temp = 0;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(s[idx] == '.') temp++;
            else {
                result = max(result, temp);
                temp = 0;
            }
        }
        
        result = max(result, temp);
        return result;
    }
};