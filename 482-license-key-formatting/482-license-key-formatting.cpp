class Solution {
public:
    
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
    }
};