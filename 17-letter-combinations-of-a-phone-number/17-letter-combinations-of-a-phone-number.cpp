class Solution {
public:
    void combinations(map<int, string>& numToCharMap, string digits, int pos, string str, vector<string>& result) {
        if(pos > digits.size()) return;
        if(pos == digits.size()) {
            result.push_back(str);
            // cout << str << endl;
            return;
        }
        
        int currVal = digits[pos] - '0';
        string currStr = numToCharMap[currVal];
        for(int i = 0; i < currStr.size(); i++) {
            combinations(numToCharMap, digits, pos + 1, str + currStr[i], result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        
        map<int, string> numToCharMap;
        
        numToCharMap[2] = "abc";
        numToCharMap[3] = "def";
        numToCharMap[4] = "ghi";
        numToCharMap[5] = "jkl";
        numToCharMap[6] = "mno";
        numToCharMap[7] = "pqrs";
        numToCharMap[8] = "tuv";
        numToCharMap[9] = "wxyz";
        
        vector<string> result;
        
        combinations(numToCharMap, digits, 0, "", result);
        
        return result;
    }
};