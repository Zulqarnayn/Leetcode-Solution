class Solution {
public:
    /*
    // :: 1st version
    
    string getStringFromStack(stack<char> &temp) {
        string tempStr = "";
        
        while(temp.size()) {
            tempStr += temp.top();
            temp.pop();
        }
        
        return tempStr;
    }
    
    string licenseKeyFormatting(string s, int k) {
        stack<string> groups;
        stack<char> temp;
        
        for(int idx = s.size() - 1; idx >= 0; idx--) {
            if(s[idx] == '-') continue;
            else {
                temp.push(toupper(s[idx]));
            }
            
            if(temp.size() == k || idx == 0) {
                groups.push(getStringFromStack(temp));
            }
        }
        
        if(temp.size() > 0)
            groups.push(getStringFromStack(temp));
        
        string result = "";
        
        while(groups.size()) {
            result += groups.top();
            if(groups.size() > 1) result += "-";
            groups.pop();
        }
        
        return result;
    }*/
    
    // :: 2nd version
    string licenseKeyFormatting(string s, int k) {
        int K = k;
        string result = "";
        
       /*
       "5F3Z-2e-9-w", K = 4
       
       idx = 10, k = 4, result = "W"
       idx = 9, k = 3, result = "W9"
       idx = 8, k = 2, result = "W9E"
       idx = 7, k = 1, result = "W9E2"
       idx = 6, k = 0, result = "W9E2-"
       idx = 6, k = 4, result = "W9E2-Z"
       
       */
        
        for(int idx = s.size() - 1; idx >= 0; idx--) {
            if(s[idx] != '-') {
                if(k == 0) {
                    result += "-";
                    k = K;
                }
                
                result += toupper(s[idx]);
                k--;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};