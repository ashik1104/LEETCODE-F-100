class Solution {
public:
    int dp[10004];
    int solve(int n)
    {
        // 1. base case
        if(n <= 3)
        {
            return n;
        }
        int x = sqrt(n);
        if(x * x == n)
        {
            return 1;
        }

        // 2. if already solved
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // 3. calculate ans from smaller sub states
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++)
        {
            ans = min(ans, 1+solve(n-i*i));
        }
        dp[n]  = ans;
        return ans;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};