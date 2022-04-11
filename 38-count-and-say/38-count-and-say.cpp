class Solution {
public:
    string sayPrevious(string s) {
        int count = 1, lastNumber = (s[0] - '0'), size = s.size();
        string result = "";
        
        for(int idx = 0; idx < size; idx++) {
            bool isConsecutiveEqual = idx < size - 1 && s[idx] == s[idx+1];
            bool isLastIndex = idx == size - 1;
            
            if(isLastIndex) {
                result += (to_string(count) + to_string(lastNumber));
            } else {
                if(isConsecutiveEqual) count++;
                else {
                    result += (to_string(count) + to_string(lastNumber));
                    count = 1;
                    lastNumber = s[idx + 1] - '0';
                }
            }
        }
        
        return result;
    }
    
    string countAndSay(int n) {
        vector<string> dp(n + 1);
        dp[1] = "1";
        dp[2] = "11";
        
        for(int idx = 3; idx <= n; idx++) {
            dp[idx] = sayPrevious(dp[idx-1]);
        }
        
        return dp[n];
    }
};