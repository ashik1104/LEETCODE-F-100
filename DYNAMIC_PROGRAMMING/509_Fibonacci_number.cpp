class Solution {
public:
    int dp[50];
    int solve(int n)
    {
        // 1. base case
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }

        // 2. if already solved return result
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // 3. calculate ans from smaller substates
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};