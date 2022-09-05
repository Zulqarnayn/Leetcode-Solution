class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashMap;
        
        for(auto c: t) hashMap[c]++;
        
        int counter = t.size(), start = 0, end = 0, minStart = 0, minLen = INT_MAX;
        int size = s.size();
        
        while(end < size) {
            if(hashMap[s[end]] > 0) counter--;
            hashMap[s[end]]--;
            end++;
            while(counter == 0) {
                // cout << end <<" " << start << endl;
                if(end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                
                hashMap[s[start]]++;
                
                if(hashMap[s[start]] > 0) counter++;
                start++;
            }
        } 
        
        if(minLen != INT_MAX) return s.substr(minStart, minLen);
        
        return "";
    }
};