class Solution {
public:
    
    string calculateResult(string s, int& index) {
        int counter = 0;
        string result = "";
        
        for(; index < s.size(); index++) {
            if(isalpha(s[index])) {
                result += s[index];
            } else if(s[index] == ']') {
                return result;
            } else if(isdigit(s[index])) {
                counter = counter * 10 + (s[index] - '0');
            } else {
                string subResult = calculateResult(s, ++index);
                while(counter--) result += subResult;
                counter = 0;
            }
        }
        
        return result;
    }
    
    string decodeString(string s) {
        int size = 0;
        return calculateResult(s, size);
    }
};