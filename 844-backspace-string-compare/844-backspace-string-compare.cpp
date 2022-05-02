class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stackS, stackT;
        
        for(int idx = 0; idx < s.size(); idx++) {
            if(s[idx] == '#') {
               if(stackS.size()) stackS.pop(); 
            } else {
                stackS.push(s[idx]);
            }
        }
        
        for(int idx = 0; idx < t.size(); idx++) {
            if(t[idx] == '#') {
               if(stackT.size()) stackT.pop(); 
            } else {
                stackT.push(t[idx]);
            }
        }
        
        cout << stackS.size() <<" " << stackT.size() << endl;
        
        while(stackS.size() && stackT.size()) {
            char topS = stackS.top();
            char topT = stackT.top();
            
            if(topS != topT) return false;
            
            stackS.pop();
            stackT.pop();
        }
        
        return stackS.empty() && stackT.empty();
    }
};