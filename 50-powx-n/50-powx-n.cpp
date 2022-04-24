class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while(n){
            if(n&1){
                n > 0 ? ans = ans * x : ans = ans / x;
            }
            x = x * x;
            n /= 2;
        }
        return ans;
    }
};