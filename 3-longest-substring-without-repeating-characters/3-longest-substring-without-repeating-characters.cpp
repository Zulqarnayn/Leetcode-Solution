class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> uMap;
        
        int counter = 0, start = 0, end = 0, maxLen = 0;
        
        while(end < s.size()) {
            if(uMap[s[end]] > 0) counter++;
            uMap[s[end]]++;
            end++;
            
            while(counter > 0) {
                if(uMap[s[start]] > 1) counter--;
                uMap[s[start]]--;
                start++;
            }
            
            maxLen = max(maxLen, end - start);
        }
        
        return maxLen;
    }
};