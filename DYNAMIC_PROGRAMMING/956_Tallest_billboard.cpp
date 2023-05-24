class Solution // answer stored at dp[n][sum]
{
public:
    int dp[21][5000 * 2 + 1];
    int solve(int n, int d, vector<int> &rods)
    {
        // 1. base case
        if (n < 0)
        {
            if (d == 0)
            {
                return 0;
            }
            else
            {
                return INT_MIN;
            }
        }

        // 2. if already solved...
        if (dp[n][5000 + d] != -1)
        {
            return dp[n][5000 + d];
        }

        // 3. calculate from smaller sub states...
        int a = solve(n - 1, d, rods);
        int b = rods[n] + solve(n - 1, d + rods[n], rods);
        int c = solve(n - 1, d - rods[n], rods);
        dp[n][5000 + d] = max({a, b, c});
        return dp[n][5000 + d];
    }
    int tallestBillboard(vector<int> &rods)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(rods.size() - 1, 0, rods);
        if (ans < 0)
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }
};