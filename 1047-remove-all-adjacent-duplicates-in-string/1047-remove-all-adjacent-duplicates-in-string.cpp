class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> charStk;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(!charStk.empty() && charStk.top() == s[idx]) {
                charStk.pop();
            } else {
                charStk.push(s[idx]);
            }
        }
        
        string result = "";
        while(!charStk.empty()) {
            result += charStk.top();
            charStk.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};