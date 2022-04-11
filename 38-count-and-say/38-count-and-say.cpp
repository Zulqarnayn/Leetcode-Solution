class Solution {
public:
    /*
    Describe the previous term!
    1, 11, 21, 1211, 111221, 312211, 12112221, 1112213211, ...

    Just Count and Say 111221 = (111)31(22)21(1)11

    Code Improvements:
    1. reduce Level Of Indentation Per Method
    2. Don’t Use The ELSE Keyword
    
    you will find more code improvment techniques 
    here (https://williamdurand.fr/2013/06/03/object-calisthenics/#5-one-dot-per-line)
    
    */
    
    string concatenate2Number(int a, int b) {
        return to_string(a) + to_string(b);
    }
    
    string sayPrevious(string s) {
        int count = 1, lastNumber = (s[0] - '0'), size = s.size();
        string result = "";
        
        for(int idx = 0; idx < size; idx++) {
            bool isConsecutiveEqual = idx < size - 1 && s[idx] == s[idx+1];
            bool isLastIndex = idx == size - 1;
            
            if(isLastIndex) {
                result += concatenate2Number(count, lastNumber);
                break;
            } 
            
            if(isConsecutiveEqual) {
                count++;
                continue;
            } 
            
            result += concatenate2Number(count, lastNumber);
            count = 1;
            lastNumber = s[idx + 1] - '0';
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