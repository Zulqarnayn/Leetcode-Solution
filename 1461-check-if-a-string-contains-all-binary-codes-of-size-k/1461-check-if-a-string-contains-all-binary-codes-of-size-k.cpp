class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        map<string, int> substringMap;
        int cnt = 0;
        
        for(int idx = 0; idx <= s.size() - k; idx++) {
            string sub = s.substr(idx, k);
            // cout << sub << " " << idx << endl;
            if(substringMap.find(sub) == substringMap.end()) {
                substringMap[sub] = 1;
                cnt++;
            }
        }
        
        int twoPowK = pow(2, k);
        // cout << twoPowK << " " << substringMap.size() << endl;
        
        return substringMap.size() >= twoPowK;
    }
};