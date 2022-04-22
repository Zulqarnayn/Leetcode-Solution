class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        unordered_map<int, string> uMap, srMap;
        
        for(int idx = 0; idx < indices.size(); idx++) {
            string sbstr = s.substr(indices[idx], sources[idx].size());
            
            if(sbstr == sources[idx]) {
                uMap[indices[idx]] = targets[idx];
                srMap[indices[idx]] = sources[idx];
            }
        }
        
        string result = "";
        for(int idx = 0; idx < s.size(); idx++) {
            if(uMap.count(idx) > 0) {
                result += uMap[idx];
                idx += srMap[idx].size() - 1;
            } else {
                result += s[idx];
            }
        }
        
        return result;
    }
};