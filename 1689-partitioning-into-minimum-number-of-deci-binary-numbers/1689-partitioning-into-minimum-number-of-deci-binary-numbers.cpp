class Solution {
public:
    int minPartitions(string n) {
        int maxValue = 0;
        
        for(auto ch: n) {
            if((ch - '0') > maxValue) maxValue = ch - '0';
        }
        
        return maxValue;
    }
};