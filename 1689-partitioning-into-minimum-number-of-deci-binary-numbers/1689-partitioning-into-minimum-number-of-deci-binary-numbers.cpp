class Solution {
public:
    int findMin(string n) {
        int mn = 0;
        for(auto ch: n) {
            if((ch - '0') > mn) mn = ch - '0';
        }
        
        return mn;
    }
    
    int minPartitions(string n) {
        int sum = 0;
        
        while(1) {
            int currMin = findMin(n);
            if(currMin == 0) return sum;
            
            sum += currMin;
            for(int idx = 0; idx < n.size(); idx++) {
                int subtractResult = (n[idx] - '0') - currMin;
                n[idx] = '0' + (subtractResult > 0 ? subtractResult : 0);
            }
        }
        
        return sum;
    }
};