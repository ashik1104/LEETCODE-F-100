class Solution
{
public:
    int dp[50];

    int solve(int n)
    {
        // 1. base case
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        // if already solved, return result
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // 3. calculate from smaller sub-states..
        dp[n] = solve(n - 1) + solve(n - 2);
        return dp[n];
    }

    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};