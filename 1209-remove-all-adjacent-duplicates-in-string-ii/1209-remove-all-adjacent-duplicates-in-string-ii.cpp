class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, char>> charStack;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(charStack.size() && charStack.top().second == s[idx]) {
                if(charStack.top().first + 1 == k) charStack.pop();
                else {
                    charStack.top().first += 1;
                }
            } else {
                charStack.push({1, s[idx]});
            }
        }
        
        string result = "";
        while(!charStack.empty()) {
            int times = charStack.top().first;
            char ch = charStack.top().second;
            
            while(times--) result += ch;
            charStack.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};