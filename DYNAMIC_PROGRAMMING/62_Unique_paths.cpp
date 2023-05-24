class Solution {
public:
    int dp[105][105];
    int unique_path(int m, int n)
    {
        // 1. base case
        if(m == 0 and n == 0)
        {
            return 1;
        }
        if(m < 0 or n < 0)
        {
            return 0;
        }

        // 2. if already solved
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        // 3. calculate from smaller sub states.
        dp[m][n] = unique_path(m - 1, n) + unique_path(m, n-1);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return unique_path(m-1, n-1);
    }
};