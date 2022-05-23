class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0;
    
        while(n) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }

        return sum;
    }
    
    bool isHappy(int n) {
        while(n != 1) {
            n = digitSquareSum(n);
            if(n == 4) return false;
        }
        
        return true;
    }
};