class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        double res = myPow(x, n/2);
        
        if(n&1) {
            if(n < 0) {
                return (res * res) / x;
            } else {
                return x * res * res;
            }
        } else {
            return res * res;
        }
    }
};