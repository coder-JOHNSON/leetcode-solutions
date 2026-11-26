// class Solution {
// public:
//     int fib(int n) {
//         if(n <= 1) return n;
//         int dp[n + 1];
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
//         return dp[n];
//     }
// };





class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int dp[3];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        return dp[n % 3];
    }
};