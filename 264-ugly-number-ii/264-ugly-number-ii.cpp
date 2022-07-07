class Solution {
public:
    bool isUgly(int n){
        if(n <= 0) return false;
        for(int i = 2 ; i < 6 ; i++){
            while(n%i==0){
                n /= i;
            }
        }
        return n == 1;
    }
    int nthUglyNumber(int n) {
        // vector<int> dp(n);
        // dp[0] = 1;
        // int a = 0, b = 0, c = 0;
        // for(int i = 1 ; i < n ; i++){
        //     dp[i] = min({dp[a]*2, dp[b]*3, dp[c]*5});
        //     if(dp[i] == dp[a] *2) a++;
        //     if(dp[i] == dp[b] *3) b++;
        //     if(dp[i] == dp[c] *5) c++;
        // }
        // return dp[n-1];
        // if(n <= 6) return n;
        // int i = 7;
        // n = n-6;
        // int ans = 0;
        // while(n){
        //     if(isUgly(i)){
        //         n--;
        //         if(n == 0){
        //             ans = i;
        //         }
        //     }
        //     i++;
        // }
        // return ans;
        set<long long> possiblenumbers, numbers;
        possiblenumbers.insert(1);
        while(numbers.size() != n){
            long long ugly = *possiblenumbers.begin();
            numbers.insert(ugly);
            possiblenumbers.erase(ugly);
            possiblenumbers.insert(ugly*2);
            possiblenumbers.insert(ugly*3);
            possiblenumbers.insert(ugly*5);
        }
        int ans = *numbers.rbegin();
        return ans;
    }
};