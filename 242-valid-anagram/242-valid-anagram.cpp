class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26, 0);
        for(auto ch: s) {
            counter[ch - 'a']++;
        }

        for(auto ch: t) {
            counter[ch - 'a']--;
        }

        for(int idx = 0; idx < 26; idx++) {
            if(counter[idx] != 0) return false;
        }

        return true;
    }
};