class Solution {
public:
    bool isPowerofTwo(int n){
        if(n == 1) return true;
        if(n <= 0 || n % 2 != 0) return false;
        return isPowerofTwo(n/2);
    }
    bool reorderedPowerOf2(int n) {
        if(isPowerofTwo(n)) return true;
        vector<int> digits(10, 0);
        while(n){
            digits[n%10]++;
            n /= 10;
        }
        int num = 0; bool flag = false;
        for(int i = 1 ; i < digits.size() ; i++){
            if(flag && digits[0] > 0){
                int zero = digits[0];
                while(zero--){
                    num = num *10;
                }
                digits[0] = 0;
            }
            for(int cnt = digits[i] ; cnt > 0 ; cnt--){
                num = num * 10 + i;
                flag = true;
            }
        }
        string number = to_string(num);
        do{
            if(isPowerofTwo(stoi(number))) return true;
        } while(next_permutation(number.begin(), number.end()));
        return false;
    }
};