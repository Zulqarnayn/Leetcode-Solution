class Solution {
public:
    int hammingWeight(uint32_t n) {
        int noOfSetBit = 0;
        while(n) {
            noOfSetBit += (n % 2);
            n = n >> 1;
        }
        
        return noOfSetBit;
    }
};