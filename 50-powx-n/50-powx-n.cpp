class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long m = abs(long(n));
        while(m){
            if(m&1){
               ans *= x;
            }
            x = x * x;
            m >>= 1;
        }
        return n > 0 ? ans : 1/ans;
    }
};