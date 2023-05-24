class Solution {
public:
    int dp[50];
    int solve(int n)
    {
        // base case
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 1;
        }

        // if already solved, return result
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // calculate result from smaller sub states...
        dp[n] = solve(n-1) + solve(n-2) + solve(n-3);
        return dp[n];
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
